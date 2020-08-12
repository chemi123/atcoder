#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct phash{
  inline size_t operator()(const pair<int,int> & p) const{
    const auto h1 = hash<int>()(p.first);
    const auto h2 = hash<int>()(p.second);
    return h1 ^ (h2 << 1);
  }
};

int main() {
  int m;
  cin >> m;
  pair<int, int> baseGrid;
  vector<pair<int, int>> relativeGrids;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    if (i == 0) {
      baseGrid = make_pair(x, y);
    } else {
      relativeGrids.emplace_back(make_pair(x - baseGrid.first, y - baseGrid.second));
    }
  }

  int n;
  cin >> n;
  unordered_set<pair<int, int>, phash> grids;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    grids.emplace(make_pair(x, y));
  }

  pair<int, int> ans;
  for (const auto& grid : grids) {
    bool found = true;
    for (const auto& relativeGrid : relativeGrids) {
      if (grids.find(make_pair(grid.first + relativeGrid.first, grid.second + relativeGrid.second)) == grids.end()) {
        found = false;
        break;
      }
    }
    if (found) ans = make_pair(grid.first - baseGrid.first, grid.second - baseGrid.second);
  }
  cout << ans.first << " " << ans.second << endl;

  return 0;
}