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

// https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_e

int bfs(const vector<string>& grids, int& sr, int& sc, int strength, int h, int w) {
  queue<pair<int, int>> q;
  vector<vector<int>> delta{vector<int>{1, 0}, vector<int>{-1, 0}, vector<int>{0, 1}, vector<int>{0, -1}};
  vector<vector<bool>> visit(h, vector<bool>(w, false));
  visit[sr][sc] = true;
  q.emplace(sr, sc);
  int step = 0;
  while (!q.empty()) {
    int size = (int)q.size();
    rep (i, size) {
      int row = q.front().first, col = q.front().second;
      q.pop();
      if (grids[row][col] - '0' == strength) {
        sr = row, sc = col;
        return step;
      }
      rep (i, 4) {
        if (row + delta[i][0] >= 0 && row + delta[i][0] < h && col + delta[i][1] >= 0 && col + delta[i][1] < w
            && grids[row + delta[i][0]][col + delta[i][1]] != 'X' && !visit[row + delta[i][0]][col + delta[i][1]]) {
          visit[row + delta[i][0]][col + delta[i][1]] = true;
          q.emplace(row + delta[i][0], col + delta[i][1]);
        }
      }
    }
    ++step;
  }
  return -1;
}

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<string> grids(h);
  int sr, sc;
  rep (i, h) cin >> grids[i];
  rep (i, h) {
    auto pos = grids[i].find("S");
    if (pos != string::npos) {
      sr = i;
      sc = (int)pos;
      break;
    }
  }
  int strength = 1;
  int ans = 0;
  rep (i, n) {
    ans += bfs(grids, sr, sc, strength + i, h, w);
  }
  cout << ans << endl;
  return 0;
}
