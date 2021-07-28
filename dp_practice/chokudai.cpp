#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

// https://atcoder.jp/contests/abc211/tasks/abc211_c

int main() {
  string s; cin >> s;
  vector<char> chokudai{'c', 'h', 'o', 'k', 'u', 'd', 'a', 'i'};

  vector<vector<int>> dp(8, vector<int>((int)s.size(), 0));
  if (s[0] == chokudai[0]) dp[0][0] = 1;
  reps (i, 1, (int)s.size()) {
    if (s[i] == chokudai[0]) dp[0][i] = dp[0][i-1] + 1;
    else dp[0][i] = dp[0][i-1];
  }
  reps (i, 1, 8) {
    reps (j, i, (int)s.size()) {
      if (s[j] == chokudai[i]) dp[i][j] = (dp[i-1][j-1] + dp[i][j-1]) % MOD;
      else dp[i][j] = dp[i][j-1];
    }
  }
  cout << dp.back().back() << endl;
  return 0;
}