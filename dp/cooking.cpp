#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
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

int main() {
  int n; cin >> n;
  vector<int> t(n);
  int sum = 0;
  rep (i, n) {
    cin >> t[i];
    sum += t[i];
  }
  vector<vector<int>> dp(n, vector<int>(sum + 1));
  dp[0][0] = 1, dp[0][t[0]] = 1;
  int maxIndex = t[0];
  rep (i, n - 1) {
    int tmp = maxIndex;
    rep (j, maxIndex + 1) {
      if (dp[i][j]) {
        dp[i+1][j] = 1;
        dp[i+1][j+t[i+1]] = 1;
        tmp = max(tmp, j + t[i+1]);
      }
    }
    maxIndex = tmp;
  }
  int half = sum / 2;
  int ans = 0;
  rep (i, sum + 1) {
    if (dp[n-1][i]) {
      if (abs(half - i) < abs(half - ans)) ans = i;
    }
  }
  cout << max(ans, sum - ans) << endl;
  return 0;
}
