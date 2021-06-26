#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <set>
#include <sstream>
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

// https://atcoder.jp/contests/abc131/tasks/abc131_c

int main() {
  ll a, b, c, d; cin >> a >> b >> c >> d;
  ll cd = lcm(c, d);
  ll ans = b - a + 1;
  ans -= ((b / c) - ((a - 1) / c));
  ans -= ((b / d) - ((a - 1) / d));
  ans += ((b / cd) - ((a - 1) / cd));
  cout << ans << endl;
  return 0;
}
