#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

// https://atcoder.jp/contests/abc075/tasks/abc075_c

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
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> bridges;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    bridges.emplace_back(make_pair(a-1, b-1));
  }

  int answer = 0;
  for (int i = 0; i < m; ++i) {
    UnionFind uf(n);
    for (int j = 0; j < m; ++j) {
      if (i == j) continue;
      uf.unite(bridges[j].first, bridges[j].second);
    }
    if (uf.groups() > 1) ++answer;
  }

  cout << answer << endl;
  return 0;
}