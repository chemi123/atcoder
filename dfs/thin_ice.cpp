#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

// https://atcoder.jp/contests/joi2009yo/tasks/joi2009yo_d

int dfs(vector<vector<int>>& grids, int row, int col, int step) {
  if (row < 0 || row >= (int)grids.size() || col < 0 || col >= (int)grids[0].size() || grids[row][col] == 0) {
    return step;
  }
  grids[row][col] = 0;
  int res = dfs(grids, row - 1, col, step + 1);
  res = max(res, dfs(grids, row + 1, col, step + 1));
  res = max(res, dfs(grids, row, col - 1, step + 1));
  res = max(res, dfs(grids, row, col + 1, step + 1));
  grids[row][col] = 1;
  return res;
}

int main() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> grids(n, vector<int>(0));
  rep (r, n) {
    rep (c, m) {
      int grid;
      cin >> grid;
      grids[r].emplace_back(grid);
    }
  }
  int ans = 0;
  rep (r, n) {
    rep (c, m) {
      if (grids[r][c] == 1) {
        ans = max(ans, dfs(grids, r, c, 0));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
