#include <vector>

using namespace std;

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
