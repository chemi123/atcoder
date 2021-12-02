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

// https://atcoder.jp/contests/abc180/tasks/abc180_d

int main() {
  ll x, y, a, b; cin >> x >> y >> a >> b;
  ll ans = 0;
  while (x < y && x < b) {
    x = x * a;
    if (x < y) ++ans;
  }
  ll rest = y - x;
  if (x < y) {
    if (rest % b == 0) ans += (((y - x) / b) - 1);
    else ans += (((y - x) / b));
  }
  cout << ans << endl;
  return 0;
}