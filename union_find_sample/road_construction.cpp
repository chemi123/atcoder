#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
  UnionFind(int n) : _parent(n, -1) {
  }

  int root(int x) {
    if (_parent[x] < 0) {
        return x;
    }
    return _parent[x] = root(_parent[x]);
  }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);

    if (x == y) {
      return;
    }
    
    if (size(x) < size(y)) {
      swap(x, y);
    }

    _parent[x] += _parent[y];
    _parent[y] = x;
  }

  int size(int x) {
      return -_parent[root(x)];
  }

  int groups() {
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
  for (size_t i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    uf.unite(a, b);
  }
  cout << uf.groups() - 1 << endl;
  return 0;
}