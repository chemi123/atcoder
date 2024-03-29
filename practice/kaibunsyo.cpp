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

// https://atcoder.jp/contests/abc206/tasks/abc206_d

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
  int n; cin >> n;
  vector<int> a(n);
  int maxNum = 0;
  rep (i, n) {
    cin >> a[i];
    maxNum = max(maxNum, a[i]);
  }
  int l = 0, r = n - 1;
  UnionFind uf(maxNum + 1);
  int ans = 0;
  while (l < r) {
    if (!uf.same(a[l], a[r])) {
      ++ans;
      uf.unite(a[l], a[r]);
    }
    ++l;
    --r;
  }
  cout << ans << endl;
  return 0;
}