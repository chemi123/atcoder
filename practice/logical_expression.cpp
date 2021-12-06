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

// https://atcoder.jp/contests/abc189/tasks/abc189_d

int main() {
  int n; cin >> n;
  vector dp(n + 1, vector<ll>(2));
  dp[0][0] = 1LL, dp[0][1] = 1LL;
  reps (i, 1, n + 1) {
    string s; cin >> s;
    if (s == "AND") {
      dp[i][0] = dp[i-1][0] * 2 + dp[i-1][1];
      dp[i][1] = dp[i-1][1];
    } else {
      dp[i][0] = dp[i-1][0];
      dp[i][1] = dp[i-1][0] + dp[i-1][1] * 2;
    }
  }
  cout << dp.back()[1] << endl;
  return 0;
}