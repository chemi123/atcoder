#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

// https://atcoder.jp/contests/abc067/tasks/arc078_a

int main() {
  int n; cin >> n;
  vector<ll> acc(n);
  rep (i, n) {
    ll a; cin >> a;
    if (i == 0) acc[i] = a;
    else acc[i] = acc[i-1] + a;
  }

  ll ans = INFL;
  rep (i, n - 1) {
    ll x = acc[i], y = acc.back() - acc[i];
    ans = min(ans, abs(x - y));
  }
  cout << ans << endl;
  return 0;
}