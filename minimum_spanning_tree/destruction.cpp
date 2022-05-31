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
using tp = tuple<ll, ll, ll>;

const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1000000007;

// https://atcoder.jp/contests/abc218/tasks/abc218_e

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
  int n, m; cin >> n >> m;
  vector<tp> edge(m);
  rep (i, m) {
    ll a, b, c; cin >> a >> b >> c; --a, --b;
    edge[i] = tp(c, a, b);
  }
  sort(edge.begin(), edge.end());
  UnionFind uf(n);
  ll ans = 0;
  for (auto [c, a, b] : edge) {
    if (uf.same(a, b) && c > 0) {
      ans += c;
    } else {
      uf.unite(a, b);
    }
  }
  cout << ans << endl;
  return 0;
}