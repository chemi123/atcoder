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

// https://atcoder.jp/contests/abc074/tasks/arc083_a

int main() {
  int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
  vector<int> dp(f + 1, -1);
  dp[a*100] = 0, dp[b*100] = 0;
  rep (w, f + 1) {
    if (dp[w] == -1) continue;
    dp[w+a*100] = max(dp[w+a*100], dp[w]);
    dp[w+b*100] = max(dp[w+b*100], dp[w]);
    if ((double)(dp[w] + c) / (w + c) <= (double)e / (100 + e) && w + c <= f) dp[w+c] = dp[w] + c;
    if ((double)(dp[w] + d) / (w + d) <= (double)e / (100 + e) && w + d <= f) dp[w+d] = dp[w] + d;
  }
  int ans = -1;
  rep (i, f + 1) {
    if (dp[i] == -1) continue;
    if (ans == -1) ans = i;
    if ((double)dp[i] / (i + dp[i]) > (double)dp[ans] / (ans + dp[ans])) ans = i;
  }
  cout << ans << " " << dp[ans] << endl;
  return 0;
}