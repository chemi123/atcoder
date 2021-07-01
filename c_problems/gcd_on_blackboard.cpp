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

// https://atcoder.jp/contests/abc125/tasks/abc125_c

int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep (i, n) cin >> a[i];

  vector<int> l(n), r(n);
  l[1] = a[0];
  reps (i, 2, n) l[i] = gcd(l[i-1], a[i-1]);
  r[n-2] = a.back();
  for (int i = n - 3; i >=0; --i) r[i] = gcd(a[i+1], r[i+1]);

  int ans = r[0];
  reps (i, 1, n) {
    if (i == n - 1) ans = max(ans, l[i]);
    else ans = max(ans, gcd(l[i], r[i]));
  }
  cout << ans << endl;
  return 0;
}
