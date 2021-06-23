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

// https://atcoder.jp/contests/abc158/tasks/abc158_c

int main() {
  double a, b; cin >> a >> b;
  bool ok = true;
  reps (ans, 1, 1500) {
    if (floor(ans * 0.08) == a && floor(ans * 0.1) == b) {
      cout << ans << endl;
      break;
    }
    if (floor(ans * 0.08) > a && floor(ans * 0.1) > b) {
      ok = false;
      break;
    }
  }
  if (!ok) {
    cout << -1 << endl;
  }
  return 0;
}
