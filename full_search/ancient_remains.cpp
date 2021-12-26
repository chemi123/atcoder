#include <iostream>
#include <unordered_set>
#include <vector>
#include <cmath>

// https://atcoder.jp/contests/joi2007ho/tasks/joi2007ho_c

using namespace std;
using DoublePair = pair<pair<int, int>, pair<int, int>>;

struct phash{
  inline size_t operator()(const pair<int,int> & p) const{
    const auto h1 = hash<int>()(p.first);
    const auto h2 = hash<int>()(p.second);
    return h1 ^ (h2 << 1);
  }
};

int area(int x1, int y1, int x2, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
  int n;
  cin >> n;
  unordered_set<pair<int, int>, phash> grids;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    grids.emplace(make_pair(x, y));
  }

  int ans = 0;
  for (const auto& [x1, y1] : grids) {
    for (const auto& [x2, y2] : grids) {
      if (x1 == x2 && y1 == y2) continue;
      int x3 = x1 + (y1 - y2);
      int x4 = x2 + (y1 - y2);
      int y3 = y1 + (x2 - x1);
      int y4 = y2 + (x2 - x1);
      int a = area(x1, y1, x2, y2);
      if (grids.find(make_pair(x3, y3)) != grids.end() &&
          grids.find(make_pair(x4, y4)) != grids.end()) {
        ans = max(ans, a);
        continue;
      }
      x3 = x1 + (y2 - y1);
      x4 = x2 + (y2 - y1);
      y3 = y1 + (x1 - x2);
      y4 = y2 + (x1 - x2);
      if (grids.find(make_pair(x3, y3)) != grids.end() &&
          grids.find(make_pair(x4, y4)) != grids.end()) ans = max(ans, a);
    }
  }
  cout << ans << endl;
  return 0;
}