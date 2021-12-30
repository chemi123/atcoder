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

// https://atcoder.jp/contests/dp/tasks/dp_c

int main() {
  int n; cin >> n;
  vector<int> dp(3);
  rep (i, n) {
    int a, b, c; cin >> a >> b >> c;
    vector<int> ndp(3);
    ndp[0] = max(dp[1] + a, dp[2] + a);
    ndp[1] = max(dp[0] + b, dp[2] + b);
    ndp[2] = max(dp[0] + c, dp[1] + c);
    swap(dp, ndp);
  }
  cout << max({dp[0], dp[1], dp[2]}) << endl;
  return 0;
}