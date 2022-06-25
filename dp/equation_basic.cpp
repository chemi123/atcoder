#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
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

// サイコロを振った目の合計がn以上になる試行回数の期待値を求める問題
// dp[i]: これまで出た目の合計がiの時、これからサイコロを振ってn以上になる試行回数の期待値
// 考え方として例えばdp[i]からdp[i+1]へは、1/6の確率で遷移する(dp[i+2]...dp[i+6]も同様)。これは逆に考えると1回の施工でiに行く確率は1/6になる。
// なので遷移式は以下のようになる。
// dp[i] = (1 / 6) * ((1 + dp[i+1]) + (1 + dp[i+2]) + (1 + dp[i+3]) + (1 + dp[i+4]) + (1 + dp[i+5]) + (1 + dp[i+6]))

int main() {
  int n; cin >> n;
  vector<double> dp(n + 6);
  for (int i = n - 1; i >= 0; --i) {
    reps (j, 1, 7) dp[i] += (1.0 + dp[i+j]) / 6;
  }
  cout << dp[0] << endl;
  return 0;
}