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

// https://atcoder.jp/contests/abc099/tasks/abc099_c

int main() {
  int n; cin >> n;
  vector<int> num(1, 1);
  reps (i, 1, 7) num.emplace_back(pow(6, i));
  reps (i, 1, 6) num.emplace_back(pow(9, i));
  sort(num.begin(), num.end());

  vector<int> dp(100001, INF);
  dp[0] = 0;
  rep (i, 100000) {
    for (auto e : num) {
      if (i + e > 100000) break;
      dp[i+e] = min(dp[i+e], dp[i] + 1);
    }
  }
  cout << dp[n] << endl;
  return 0;
}