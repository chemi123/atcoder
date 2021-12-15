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

// https://atcoder.jp/contests/jsc2019-qual/tasks/jsc2019_qual_b

int main() {
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  rep (i, n) cin >> a[i];
  ll inversionNum1 = 0, inversionNum2 = 0;
  rep (i, n) reps (j, i + 1, n) if (a[i] > a[j]) ++inversionNum1;
  rep (i, n) rep (j, n) if (a[i] > a[j]) ++inversionNum2;
  ll ans = inversionNum1 * k % MOD;
  ll tmp = k * (k - 1) / 2LL % MOD;
  tmp = tmp * inversionNum2 % MOD;
  ans = (ans + tmp) % MOD;
  cout << ans << endl;
  return 0;
}