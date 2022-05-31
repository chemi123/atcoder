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
using tp = tuple<int, int, int>;

const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1000000007;

using namespace std;

// 最小全域木例題
// 方針は辺をコストの小さい順にソートし、ソートされた辺を繋げていく。すでに連結なら繋げない。
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=ja

class UnionFind {
public:
  UnionFind(int n) : _parent(n, -1) {
  }

  int root(int x) {
    if (_parent[x] < 0) return x;
    return _parent[x] = root(_parent[x]);
  }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (size(x) < size(y)) swap(x, y);
    _parent[x] += _parent[y];
    _parent[y] = x;
  }

  int size(int x) {
    return -_parent[root(x)];
  }
  
  bool same(int x, int y) {
    return root(x) == root(y);
  }

  int groups() {
    int res = 0;
    for (auto &e : _parent) {
      if (e < 0) ++res;
    }
    return res;
  }

private:
  vector<int> _parent;
};

int main() {
  int v, e; cin >> v >> e;
  vector<tp> edge(e);
  rep (i, e) {
    int s, t, w; cin >> s >> t >> w;
    edge.emplace_back(tp(w, s, t));
  }
  sort(edge.begin(), edge.end());
  UnionFind uf(v);
  ll ans = 0;
  for (auto [w, s, t] : edge) {
    if (uf.same(s, t)) continue;
    uf.unite(s, t);
    ans += w;
  }
  cout << ans << endl;
  return 0;
}