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

int bfs(const vector<vector<int>>& vWalls, const vector<vector<int>>& hWalls, int row, int col) {
  queue<pair<int, int>> que;
  que.emplace(make_pair(0, 0));
  vector<pair<int, int>> drdc{make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};
  vector<vector<bool>> visit(row, vector<bool>(col, false));
  visit[0][0] = true;
  int res = 1;
  while (!que.empty()) {
    int size = (int)que.size();
    rep (i, size) {
      auto [cr, cc] = que.front();
      que.pop();
      if (cr == row - 1 && cc == col - 1) return res;
      for (auto [dr, dc] : drdc) {
        int nr = cr + dr, nc = cc + dc;
        if (nr < 0 || nr >= row || nc < 0 || nc >= col || visit[nr][nc]) continue;
        if (dr == -1 && hWalls[cr-1][cc]) continue;
        if (dr == 1 && hWalls[cr][cc]) continue;
        if (dc == -1 && vWalls[cr][cc-1]) continue;
        if (dc == 1 && vWalls[cr][cc]) continue;
        que.emplace(make_pair(nr, nc));
        visit[nr][nc] = true;
      }
    }
    ++res;
  }
  return 0;
}

int main() {
  while (1) {
    int row, col;
    cin >> col >> row;
    if (row == 0 && col == 0) break;
    vector<vector<int>> vWalls(row, vector<int>(col-1, 0));
    vector<vector<int>> hWalls(row-1, vector<int>(col, 0));
    rep (i, row) {
      rep (j, col-1) cin >> vWalls[i][j];
      if (i < row - 1) rep (j, col) cin >> hWalls[i][j];
    }
    cout << bfs(vWalls, hWalls, row, col) << endl;;
  }
  return 0;
}