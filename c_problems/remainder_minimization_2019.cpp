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

// https://atcoder.jp/contests/abc133/tasks/abc133_c

int main() {
  ll L, R; cin >> L >> R;
  ll ans = 2019;
  for (ll l = L; l < R; ++l) {
    for (ll r = l + 1; r <= R; ++r) {
      ll tmp = (l % 2019) * (r % 2019) % 2019;
      ans = min(ans, tmp);
      if (ans == 0) break;
    }
    if (ans == 0) break;
  }
  cout << ans << endl;
  return 0;
}
