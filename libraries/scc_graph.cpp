#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define reps(i, s, n) for (int i = s; i < n; i++)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1000000007;

// atcoder版
namespace atcoder {
namespace internal {

template <class E> struct csr {
  std::vector<int> start;
  std::vector<E> elist;
  explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
    : start(n + 1), elist(edges.size()) {
    for (auto e : edges) {
      start[e.first + 1]++;
    }
    for (int i = 1; i <= n; i++) {
      start[i] += start[i - 1];
    }
    auto counter = start;
    for (auto e : edges) {
      elist[counter[e.first]++] = e.second;
    }
  }
};

struct scc_graph {
  public:
    explicit scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    // @return pair of (# of scc, scc id)
    std::pair<int, std::vector<int>> scc_ids() {
      auto g = csr<edge>(_n, edges);
      int now_ord = 0, group_num = 0;
      std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
      visited.reserve(_n);
      auto dfs = [&](auto self, int v) -> void {
        low[v] = ord[v] = now_ord++;
        visited.push_back(v);
        for (int i = g.start[v]; i < g.start[v + 1]; i++) {
          auto to = g.elist[i].to;
          if (ord[to] == -1) {
            self(self, to);
            low[v] = std::min(low[v], low[to]);
          } else {
            low[v] = std::min(low[v], ord[to]);
          }
        }
        if (low[v] == ord[v]) {
          while (true) {
            int u = visited.back();
            visited.pop_back();
            ord[u] = _n;
            ids[u] = group_num;
            if (u == v) break;
          }
          group_num++;
        }
      };
      for (int i = 0; i < _n; i++) {
        if (ord[i] == -1) dfs(dfs, i);
      }
      for (auto& x : ids) {
        x = group_num - 1 - x;
      }
      return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
      auto ids = scc_ids();
      int group_num = ids.first;
      std::vector<int> counts(group_num);
      for (auto x : ids.second) counts[x]++;
      std::vector<std::vector<int>> groups(ids.first);
      for (int i = 0; i < group_num; i++) {
        groups[i].reserve(counts[i]);
      }
      for (int i = 0; i < _n; i++) {
        groups[ids.second[i]].push_back(i);
      }
      return groups;
    }

  private:
    int _n;
    struct edge {
      int to;
    };
    std::vector<std::pair<int, edge>> edges;
};
}  // namespace internal
struct scc_graph {
  public:
    scc_graph() : internal(0) {}
    explicit scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
      int n = internal.num_vertices();
      assert(0 <= from && from < n);
      assert(0 <= to && to < n);
      internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

  private:
    internal::scc_graph internal;
};
}  // namespace atcoder

// 自前scc、トポロジカルソートできなかったが取り敢えず置いておく
// 0indexから始まるグラフに対応(1indexだとout of boundする)
class SccGraph {
public:

  SccGraph(vector<vector<int>>& graph) :
    _graph(graph),
    _rgraph(vector<vector<int>>((int)graph.size())),
    _label(vector<int>((int)graph.size())),
    _n((int)graph.size())
  {
    for (int i = 0; i < _n; ++i) {
      for (auto e : _graph[i]) _rgraph[e].emplace_back(i);
    }

    vector<bool> visit(_n);
    int cnt = 0;
    for (int i = 0; i < _n; ++i) _labeling(visit, i, cnt);
    for (int i = 0; i < _n; ++i) visit[i] = false;

    for (int i = _n - 1; i >= 0; --i) {
      vector<int> group;
      _grouping(group, visit, _label[i]);
      if (group.size()) _scc.emplace_back(group);
    }
  }

  const vector<vector<int>>& getScc() { return _scc; }

private:
  void _labeling(vector<bool>& visit, int current, int& cnt) {
    if (visit[current]) return;
    visit[current] = true;
    for (auto next : _graph[current]) _labeling(visit, next, cnt);
    _label[cnt] = current;
    ++cnt;
  }

  void _grouping(vector<int>& group, vector<bool>& visit, int current) {
    if (visit[current]) return;
    visit[current] = true;
    group.emplace_back(current);
    for (auto next : _rgraph[current]) _grouping(group, visit, next);
  }

  vector<vector<int>> _graph, _rgraph;
  // 例えば[[2, 3, 1], [4], [5, 6]]のような形で強連結成分を入れておくためのコンテナ(要素が一つだけの場合もあり得る)
  vector<vector<int>> _scc;
  vector<int> _label;
  int _n;
};

using namespace atcoder;

// 以下の問題を解いて簡単な動作検証
// https://atcoder.jp/contests/typical90/tasks/typical90_u 
int main() {
  int n, m; cin >> n >> m;
  scc_graph sg(n);
  rep (i, m) {
    int a, b; cin >> a >> b; --a, --b;
    sg.add_edge(a, b);
  }
  ll ans = 0;
  for (auto& v : sg.scc()) {
    ll nodes = (ll)v.size();
    ans += nodes * (nodes - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}