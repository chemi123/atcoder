#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1166&lang=jp

int bfs(const vector<vector<int>>& vertical, const vector<vector<int>>& horizon, int h, int w) {
  vector<vector<int>> deltas{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  vector<vector<bool>> visit(h, vector<bool>(w, false));
  queue<pair<int, int>> q;
  visit[0][0] = true;
  q.emplace(0, 0);
  auto isAvailable = [h, w](int row, int col){ return (row >= 0 && row < h && col >= 0 && col < w); };
  int steps = 1;
  while (!q.empty()) {
    int size = (int)q.size();
    for (int i = 0; i < size; ++i) {
      int row = q.front().first, col = q.front().second;
      q.pop();
      if (row == h - 1 && col == w - 1) return steps;
      for (const auto& delta : deltas) {
        int dr = delta[0], dc = delta[1];
        int nextRow = row + dr, nextCol = col + dc;
        if (isAvailable(nextRow, nextCol) && !visit[nextRow][nextCol]) {
          bool isPartitioned = false;
          if (abs(dr) > 0) {
            if (dr == 1) isPartitioned = (horizon[row][col] == 1);
            else isPartitioned = (horizon[row-1][col] == 1);
          } else {
            if (dc == 1) isPartitioned = (vertical[row][col] == 1);
            else isPartitioned = (vertical[row][col-1] == 1);
          }
          if (isPartitioned) continue;
          visit[nextRow][nextCol] = true;
          q.emplace(nextRow, nextCol);
        }
      }
    }
    ++steps;
  }
  return 0;
}

int main() {
  while (1) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) break;
    vector<vector<int>> vertical(h, vector<int>(w - 1));
    vector<vector<int>> horizon(h - 1, vector<int>(w, 0));
    int r = 0;
    rep (i, h * 2 - 1) {
      if (i % 2 == 0) {
        rep (j, w - 1) cin >> vertical[r][j];
      } else {
        rep (j, w) cin >> horizon[r][j];
        ++r;
      }
    }
    cout << bfs(vertical, horizon, h, w) << endl;
  }
  return 0;
}
