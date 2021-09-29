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
const ll MOD = 998244353;

int main() {
  int n; cin >> n;
  queue<ll> a;
  rep (i, n) {
    ll num; cin >> num;
    a.emplace(num);
  }
  vector dp(n, vector<ll>(10));
  dp[0][a.front()] = 1;
  a.pop();
  rep (i, n - 1) {
    rep (j, 10) {
      ll x = j, y = a.front();
      dp[i + 1][(x + y) % 10] += dp[i][x];
      dp[i + 1][(x + y) % 10] %= MOD;
      dp[i + 1][(x * y) % 10] += dp[i][x];
      dp[i + 1][(x * y) % 10] %= MOD;
    }
    a.pop();
  }
  rep (i, 10) cout << dp.back()[i] << endl;
  return 0;
}