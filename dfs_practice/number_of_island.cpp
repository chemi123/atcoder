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

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160&lang=jp

void dfs(vector<vector<int>>& grids, int row, int col) {
  if (row < 0 || row >= (int)grids.size() || col < 0 || col >= (int)grids[0].size() || grids[row][col] == 0) {
    return;
  }
  grids[row][col] = 0;
  dfs(grids, row - 1, col - 1);
  dfs(grids, row - 1, col);
  dfs(grids, row - 1, col + 1);
  dfs(grids, row, col - 1);
  dfs(grids, row, col + 1);
  dfs(grids, row + 1, col - 1);
  dfs(grids, row + 1, col);
  dfs(grids, row + 1, col + 1);
}

int main() {
  while (1) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) break;
    vector<vector<int>> grids;
    rep (i, h) {
      grids.emplace_back(vector<int>(0));
      rep (j, w) {
        int c;
        cin >> c;
        grids[i].emplace_back(c);
      }
    }

    int ans = 0;
    rep (row, h) {
      rep (col, w) {
        if (grids[row][col] == 1) {
          dfs(grids, row, col);
          ++ans;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}