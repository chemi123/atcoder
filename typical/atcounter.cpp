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

// https://atcoder.jp/contests/typical90/tasks/typical90_h

int main() {
  int n; cin >> n;
  string s; cin >> s;
  vector dp(7, vector<ll>(n));
  string atcoder = "atcoder";
  if (s[0] == atcoder[0]) dp[0][0] = 1;
  reps (i, 1, n) {
    if (s[i] == atcoder[0]) dp[0][i] = dp[0][i-1] + 1;
    else dp[0][i] = dp[0][i-1];
  }

  reps (i, 1, 7) {
    reps (j, i, n) {
      if (s[j] == atcoder[i]) dp[i][j] = (dp[i-1][j-1] + dp[i][j-1]) % MOD;
      else dp[i][j] = dp[i][j-1];
    }
  }
  cout << dp.back().back() << endl;
  return 0;
}