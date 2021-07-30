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

// https://atcoder.jp/contests/abc063/tasks/arc075_a

int main() {
  int n; cin >> n;
  vector<int> s(n);
  int sum = 0;
  rep (i, n) {
    cin >> s[i];
    sum += s[i];
  }

  sort(s.begin(), s.end());
  vector<vector<bool>> dp(n, vector<bool>(sum + 1));
  dp[0][0] = true, dp[0][s[0]] = true;

  reps (i, 1, n) {
    rep (j, sum + 1) {
      if (dp[i-1][j]) {
        dp[i][j] = true;
        if (j + s[i] <= sum) dp[i][j+s[i]] = true;
      }
    }
  }

  for (int i = sum; i >= 0; --i) {
    if ((i % 10 != 0 && dp[n-1][i]) || i == 0) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}