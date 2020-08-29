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

// https://atcoder.jp/contests/abc007/tasks/abc007_3

bool available(const vector<string>& grids, int r, int c) {
  if (r < 0 || r >= (int)grids.size() || c < 0 || c >= (int)grids[0].size() || grids[r][c] == '#') return false;
  return true;
}

int main() {
  int r, c;
  cin >> r >> c;
  int sr, sc;
  cin >> sr >> sc;
  --sr, --sc;
  int gr, gc;
  cin >> gr >> gc;
  --gr, --gc;
  vector<string> grids(r, "");
  rep (i, r) cin >> grids[i];

  queue<pair<int, int>> q;
  vector<vector<int>> dxdy{vector<int>{-1, 0}, vector<int>{1, 0}, vector<int>{0, -1}, vector<int>{0, 1}};
  vector<vector<bool>> visit(r, vector<bool>(c, false));
  int step = 0;

  q.emplace(sr, sc);
  visit[sr][sc] = true;
  while (!q.empty()) {
    int size = (int)q.size();
    for (int i = 0; i < size; ++i) {
      int row = q.front().first, col = q.front().second;
      q.pop();
      if (row == gr && col == gc) {
        cout << step << endl;
        return 0;
      }
      for (auto& v : dxdy) {
        if (available(grids, row + v[0], col + v[1]) && !visit[row + v[0]][col + v[1]]) {
          visit[row + v[0]][col + v[1]] = true;
          q.emplace(row + v[0], col + v[1]);
        }
      }
    }
    ++step;
  }
  cout << -1 << endl;
  return 0;
}