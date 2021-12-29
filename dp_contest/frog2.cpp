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

// https://atcoder.jp/contests/dp/tasks/dp_b

int main() {
  int n, k; cin >> n >> k;
  vector<int> h(n);
  rep (i, n) cin >> h[i];
  vector<int> dp(n, INF);
  dp[0] = 0;
  rep (i, n - 1) {
    reps (j, 1, k + 1) {
      if (i + j >= n) break;
      dp[i+j] = min(dp[i+j], dp[i] + abs(h[i] - h[i+j]));
    }
  }
  cout << dp.back() << endl;
  return 0;
}