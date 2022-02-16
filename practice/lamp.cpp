#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
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

// https://atcoder.jp/contests/abc129/tasks/abc129_d

int main() {
  int h, w; cin >> h >> w;
  vector<string> s(h);
  rep (i, h) cin >> s[i];
  vector vcnt(h, vector<int>(w)), hcnt(h, vector<int>(w));
  rep (row, h) {
    int left = 0;
    while (left < w) {
      if (s[row][left] == '#') {
        ++left;
        continue;
      }
      int right = left;
      while (right < w && s[row][right] != '#') ++right;
      reps (i, left, right) hcnt[row][i] = right - left;
      left = right;
    }
  }
  rep (col, w) {
    int top = 0;
    while (top < h) {
      if (s[top][col] == '#') {
        ++top;
        continue;
      }
      int bottom = top;
      while (bottom < h && s[bottom][col] != '#') ++bottom;
      reps (i, top, bottom) vcnt[i][col] = bottom - top;
      top = bottom;
    }
  }
  int ans = 0;
  rep (row, h) rep (col, w) if (s[row][col] == '.') ans = max(ans, vcnt[row][col] + hcnt[row][col] - 1);
  cout << ans << endl;
  return 0;
}