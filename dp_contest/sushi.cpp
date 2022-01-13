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

// https://atcoder.jp/contests/dp/tasks/dp_j

double calcDp(vector<vector<vector<double>>>& dp, int i, int j, int k, int n) {
  if (i == 0 && j == 0 && k == 0) return dp[0][0][0] = 0;
  if (dp[i][j][k] != -1) return dp[i][j][k];
  double res = 0.0;
  if (i > 0) res += (i * calcDp(dp, i - 1, j, k, n));
  if (j > 0) res += (j * calcDp(dp, i + 1, j - 1, k, n));
  if (k > 0) res += (k * calcDp(dp, i, j + 1, k - 1, n));
  res += n;
  res *= 1.0 / (i + j + k);
  return dp[i][j][k] = res;
}

int main() {
  int n; cin >> n;
  int one = 0, two = 0, three = 0;
  rep (i, n) {
    int a; cin >> a;
    if (a == 1) ++one;
    else if (a == 2) ++two;
    else ++three;
  }
  vector dp(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1, -1)));
  cout << fixed << setprecision(10) << calcDp(dp, one, two, three, n) << endl;
  return 0;
}