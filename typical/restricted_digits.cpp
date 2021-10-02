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

// https://atcoder.jp/contests/typical90/tasks/typical90_e

int main() {
  ll N, B, K; cin >> N >> B >> K;
  vector<int> c(K);
  rep (i, K) cin >> c[i];
  vector dp(N + 1, vector<ll>(B));
  dp[0][0] = 1;
  rep (i, N) {
    rep (j, B) {
      rep (k, K) {
        int next = (j * 10 + c[k]) % B;
        dp[i+1][next] += dp[i][j];
        dp[i+1][next] %= MOD;
      }
    }
  }
  cout << dp.back()[0] << endl;
  return 0;
}