#include <algorithm>
#include <bitset>
#include <cassert>
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

// https://atcoder.jp/contests/abc251/tasks/abc251_e

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  rep (i, n) cin >> a[i];
  vector<ll> dp1(n, INFL), dp2(n - 1, INFL);;
  dp1[0] = a[0], dp1[1] = a[0];
  reps (i, 2, n) {
    dp1[i] = min({dp1[i], dp1[i-1] + a[i-1], dp1[i-1] + a[i]});
    if (i < n - 1) dp1[i+1] = dp1[i-1] + a[i];
  }
  dp2[0] = a.back();
  reps (i, 1, n - 1) {
    dp2[i] = min({dp2[i], dp2[i-1] + a[i-1], dp2[i-1] + a[i]});
    if (i < n - 2) dp2[i+1] = dp2[i-1] + a[i];
  }
  cout << min(dp1.back(), dp2.back()) << endl;
  return 0;
}