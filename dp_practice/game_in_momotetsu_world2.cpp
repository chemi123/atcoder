#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define reps(i, s, n) for (int i = s; i < n; i++)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1000000007;

// https://atcoder.jp/contests/abc201/submissions/22757929
// 再帰を使った実装　

int f(const vector<vector<int>>& board, vector<vector<int>>& cache, int row, int col) {
  int h = board.size(), w = board[0].size();
  if (row == h - 1 && col == w - 1) return 0;
  if (cache[row][col] != -1) return cache[row][col];
  bool takahashi = (row + col) % 2 == 0 ? true : false;
  int res = takahashi ? -INF : INF;
  if (takahashi) {
    if (row < h - 1) res = max(res, f(board, cache, row + 1, col) + board[row+1][col]);
    if (col < w - 1) res = max(res, f(board, cache, row, col + 1) + board[row][col+1]);
  } else {
    if (row < h - 1) res = min(res, f(board, cache, row + 1, col) - board[row+1][col]);
    if (col < w - 1) res = min(res, f(board, cache, row, col + 1) - board[row][col+1]);
  }
  cache[row][col] = res;
  return res;
}

int main() {
  int h, w; cin >> h >> w;
  vector<vector<int>> board(h, vector<int>(w));
  rep (row, h) {
    string s; cin >> s;
    rep (col, w) {
      if (s[col] == '+') board[row][col] = 1;
      else board[row][col] = -1;
    }
  }
  vector<vector<int>> cache(h, vector<int>(w, -1));
  int ans = f(board, cache, 0, 0);
  if (ans > 0) cout << "Takahashi" << endl;
  else if (ans < 0) cout << "Aoki" << endl;
  else cout << "Draw" << endl;
  return 0;
}