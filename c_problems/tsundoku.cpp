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

// https://atcoder.jp/contests/abc191/tasks/abc191_c

int main() {
  int n, m; cin >> n >> m;
  ll k; cin >> k;
  vector<ll> a(n + 1), b(m + 1);
  rep (i, n) {
    cin >> a[i+1];
    a[i+1] += a[i];
  }
  rep (i, m) {
    cin >> b[i+1];
    b[i+1] += b[i];
  }

  int ans = 0;
  rep (i, n + 1) {
    ll limit = k - a[i];
    if (limit < 0) break;
    int index = upper_bound(b.begin(), b.end(), limit) - b.begin();
    ans = max(ans, i + index - 1);
  }
  cout << ans << endl;

  return 0;
}
