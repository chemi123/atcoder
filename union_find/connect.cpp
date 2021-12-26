#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

// https://atcoder.jp/contests/abc049/tasks/arc065_b

class UnionFind {
public:
  UnionFind(int n) : _parentRoad(n, -1), _parentRail(n, -1) {
  }

  int rootRoad(int x) {
    if (_parentRoad[x] < 0) return x;
    return _parentRoad[x] = rootRoad(_parentRoad[x]);
  }

  int rootRail(int x) {
    if (_parentRail[x] < 0) return x;
    return _parentRail[x] = rootRail(_parentRail[x]);
  }

  void uniteRoad(int x, int y) {
    x = rootRoad(x);
    y = rootRoad(y);
    if (x == y) return;
    if (sizeRoad(x) < sizeRoad(y)) swap(x, y);
    _parentRoad[x] += _parentRoad[y];
    _parentRoad[y] = x;
  }

  void uniteRail(int x, int y) {
    x = rootRail(x);
    y = rootRail(y);
    if (x == y) return;
    if (sizeRail(x) < sizeRail(y)) swap(x, y);
    _parentRail[x] += _parentRail[y];
    _parentRail[y] = x;
  }

  int sizeRoad(int x) {
    return -_parentRoad[rootRoad(x)];
  }

  int sizeRail(int x) {
    return -_parentRail[rootRail(x)];
  }

  void makeMap() {
    for (int i = 0; i < _parentRoad.size(); ++i) {
      stringstream ss;
      ss << rootRoad(i) << "_" << rootRail(i);
      _map[ss.str()]++;
    }
  }

  int numConnections(int x) {
    stringstream ss;
    ss << rootRoad(x) << "_" << rootRail(x);
    return _map[ss.str()];
  }

private:
  vector<int> _parentRoad;
  vector<int> _parentRail;
  unordered_map<string, int> _map;
};

int main() {
  int n, k, l;
  cin >> n >> k >> l;
  UnionFind uf(n);
  for (int i = 0; i < k; ++i) {
    int p, q;
    cin >> p >> q;
    uf.uniteRoad(p-1, q-1);
  }
  for (int i = 0; i < l; ++i) {
    int r, s;
    cin >> r >> s;
    uf.uniteRail(r-1, s-1);
  }
  uf.makeMap();
  for (int i = 0; i < n; ++i) {
    cout << uf.numConnections(i) << endl;
  }
  return 0;
}