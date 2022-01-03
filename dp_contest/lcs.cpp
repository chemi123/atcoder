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

// https://atcoder.jp/contests/dp/tasks/dp_f

int main() {
  string s, t; cin >> s >> t;
  int snum = (int)s.size(), tnum = (int)t.size();
  vector dp(snum + 1, vector<int>(tnum + 1));
  reps (i, 1, snum + 1) {
    reps (j, 1, tnum + 1) {
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      if (s[i-1] == t[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
    }
  }
  string ans("");
  int len = dp.back().back();
  int i = snum, j = tnum;
  while (len > 0) {
    if (s[i-1] == t[j-1]) {
      ans = s[i-1] + ans;
      --i;
      --j;
      --len;
    } else if (dp[i-1][j] == dp[i][j]) {
      --i;
    } else if (dp[i][j-1] == dp[i][j]) {
      --j;
    }
  }
  cout << ans << endl;
  return 0;
}