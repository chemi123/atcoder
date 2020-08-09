#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
  UnionFind(int n) : _parent(n, -1) {
  }

  int findRoot(int x) {
    if (_parent[x] < 0) {
      return x;
    }
    _parent[x] = findRoot(_parent[x]);
    return _parent[x];
  }

  void unite(int x, int y) {
    x = findRoot(x);
    y = findRoot(y);

    if (x == y) {
      return;
    }

    if (getSize(x) > getSize(y)) {
      swap(x, y);
    }

    _parent[x] += _parent[y];
    _parent[y] = x;
  }

  bool isSame(int x, int y) {
    return findRoot(x) == findRoot(y);
  }

  int getSize(int x) {
    return -_parent[findRoot(x)];
  }

  int getGroupNum() {
    int res = 0;
    for (size_t i = 1; i < _parent.size(); ++i) {
      if (_parent.at(i) < 0) {
        ++res;
      }
    }
    return res;
  }

private:
  vector<int> _parent;
};

int main() {
  int n, m;
  cin >> n >> m;
  UnionFind uf(n+1);

  vector<int> a(m, 0), b(m, 0);
  for (int i = 0; i < m; ++i) {
    cin >> a[i] >> b[i];
  }

  vector<uint64_t> ans(m, 0);
  ans[m-1] = (uint64_t)n * (n - 1) / 2;
  for (int i = m - 1; i >= 1; --i) {
    if (!uf.isSame(a[i], b[i])) {
      ans[i-1] = ans[i] - (uint64_t)uf.getSize(a[i]) * uf.getSize(b[i]);
      uf.unite(a[i], b[i]);
    } else {
      ans[i-1] = ans[i];
    }
  }
  for (auto &e : ans) {
    cout << e << endl;
  }
  return 0;
}