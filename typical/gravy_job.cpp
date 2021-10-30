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

// https://atcoder.jp/contests/typical90/tasks/typical90_k

int main() {
  int n; cin >> n;
  vector<tuple<ll, ll, ll>> dcs(n);
  rep (i, n) {
    ll d, c, s; cin >> d >> c >> s;
    dcs[i] = tuple<ll, ll, ll>(d, c, s);
  }
  sort(dcs.begin(), dcs.end());

  int maxD = 5001;
  vector dp(n, vector<ll>(maxD));
  reps (i, 1, maxD) {
    auto [d, c, s] = dcs[0];
    if (c <= i && i <= d) dp[0][i] = s;
    else dp[0][i] = dp[0][i-1];
  }

  reps (i, 1, n) {
    auto [d, c, s] = dcs[i];
    reps (j, 1, maxD) {
      if (c <= j && j <= d) dp[i][j] = max(dp[i-1][j], dp[i-1][j-c] + s);
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  cout << dp.back().back() << endl;
  return 0;
}