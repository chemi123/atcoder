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

int main() {
  int n; cin >> n;
  vector<int> h(n);
  rep (i, n) cin >> h[i];
  vector<int> dp(n, INF);
  dp[0] = 0;
  rep (i, n - 1) {
    dp[i+1] = min(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
    if (i < n - 2) dp[i+2] = min(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
  }
  cout << dp.back() << endl;
  return 0;
}