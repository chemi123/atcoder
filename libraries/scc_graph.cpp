#include <algorithm>
#include <bitset>
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

// 0indexから始まるグラフに対応(1indexだとout of boundする)
class SccGraph {
public:

  // できればlate initializeしたい
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
  // 例えば[[2, 3, 1], [4], [5, 6]]のような形で強連結成分を入れておくためのコンテナ(一つだけの場合もあり得る)
  vector<vector<int>> _scc;
  vector<int> _label;
  int _n;
};

// 以下の問題を解いて簡単な動作検証
// https://atcoder.jp/contests/typical90/tasks/typical90_u 
int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n);
  rep (i, m) {
    int a, b; cin >> a >> b; --a, --b;
    graph[a].emplace_back(b);
  }
  SccGraph scc_graph(graph);
  ll ans = 0;
  for (auto& v : scc_graph.getScc()) {
    ll nodes = (ll)v.size();
    ans += nodes * (nodes - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}