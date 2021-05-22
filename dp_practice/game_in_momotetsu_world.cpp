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

int main() {
  int h, w; cin >> h >> w;
  vector<vector<int>> board(h, vector<int>(w, 0));
  rep (row, h) {
    string str; cin >> str;
    rep (col, w) {
      if (str[col] == '+') board[row][col] = 1;
      else board[row][col] = -1;
    }
  }
  vector<vector<int>> dp(h, vector<int>(w, 0));
  for (int row = h - 1; row >= 0; --row) {
    for (int col = w - 1; col >= 0; --col) {
      if (row == h - 1 && col == w - 1) continue;
      if ((row + col) % 2 == 0) {
        dp[row][col] = -INF;
        if (row < h - 1) dp[row][col] = max(dp[row][col], dp[row+1][col] + board[row+1][col]);
        if (col < w - 1) dp[row][col] = max(dp[row][col], dp[row][col+1] + board[row][col+1]);
      } else {
        dp[row][col] = INF;
        if (row < h - 1) dp[row][col] = min(dp[row][col], dp[row+1][col] - board[row+1][col]);
        if (col < w - 1) dp[row][col] = min(dp[row][col], dp[row][col+1] - board[row][col+1]);
      }
    }
  }
  if (dp[0][0] == 0) cout << "Draw" << endl;
  else if (dp[0][0] > 0) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
  return 0;
}
