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

// https://atcoder.jp/contests/typical90/tasks/typical90_l

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
  int h, w, q; cin >> h >> w >> q;
  vector graph(h, vector<int>(w));
  vector<pi> drdc{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  UnionFind uf(2001 * 2001);
  auto f = [w](int r, int c) { return w * r + c + 1;};
  rep (i, q) {
    int t; cin >> t;
    if (t == 2) {
      int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2; --r1, --c1, --r2, --c2;
      auto f1 = f(r1, c1);
      auto f2 = f(r2, c2);
      if (uf.same(f1, f2) && graph[r1][c1] == 1 && graph[r2][c2] == 1) cout << "Yes" << endl;
      else cout << "No" << endl;
      continue;
    }

    int r, c; cin >> r >> c; --r, --c;
    auto fc = f(r, c);
    graph[r][c] = 1;
    for (auto [dr, dc] : drdc) {
      int nr = r + dr, nc = c + dc;
      if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
      if (graph[nr][nc] == 0) continue;
      auto fn = f(nr, nc);
      uf.unite(fc, fn);
    }
  }
  return 0;
}