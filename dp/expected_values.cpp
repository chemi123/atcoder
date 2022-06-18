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

// 解説 https://compro.tsutaj.com//archive/180220_probability_dp.pdf
// https://yukicoder.me/problems/no/65

int main() {
  int k; cin >> k;
  vector<double> dp(k + 6);
  for (int i = k - 1; i >= 0; --i) {
    dp[i] = 1;
    reps (j, 1, 7) dp[i] += (dp[i+j] / 6);
  }
  cout << dp[0] << endl;
  return 0;
}