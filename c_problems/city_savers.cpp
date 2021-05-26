#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

// https://atcoder.jp/contests/abc135/tasks/abc135_c

int main() {
  ll n; cin >> n;
  vector<ll> a(n+1), b(n);
  rep (i, n + 1) cin >> a[i];
  rep (i, n) cin >> b[i];
  ll ans = 0;
  rep (i, n) {
    if (a[i] >= b[i]) {
      ans += b[i];
      continue;
    }
    ans += a[i];
    b[i] -= a[i];
    ans += min(a[i+1], b[i]);
    a[i+1] = (a[i+1] - b[i]) >= 0 ? a[i+1] - b[i] : 0;
  }
  cout << ans << endl;
  return 0;
}