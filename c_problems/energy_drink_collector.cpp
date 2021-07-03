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

// https://atcoder.jp/contests/abc121/tasks/abc121_c

int main() {
  ll n, m; cin >> n >> m;
  vector<pl> p(n);
  rep (i, n) {
    ll a, b; cin >> a >> b;
    p[i] = pl(a, b);
  }
  sort(p.begin(), p.end());
  ll ans = 0;
  for (auto [a, b] : p) {
    if (m <= b) {
      ans += a * m;
      break;
    }
    ans += a * b;
    m -= b;
  }
  cout << ans << endl;
  return 0;
}
