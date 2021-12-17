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

// https://atcoder.jp/contests/abc051/tasks/abc051_b

int main() {
  int k, s; cin >> k >> s;
  int ans = 0;
  rep (z, k + 1) {
    int rest = s - z;
    if (rest > k * 2) continue;
    if (rest >= k) ans += (2 * k - rest + 1);
    else if (rest >= 0) ans += (rest + 1);
  }
  cout << ans << endl;
  return 0;
}