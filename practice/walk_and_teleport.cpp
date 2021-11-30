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

// https://atcoder.jp/contests/arc067/tasks/arc067_b

int main() {
  ll n, a, b; cin >> n >> a >> b;
  vector<ll> x(n);
  rep (i, n) cin >> x[i];
  ll ans = 0;
  reps (i, 1, n) {
    if ((x[i] - x[i-1]) * a < b) ans += (x[i] - x[i-1]) * a;
    else ans += b;
  }
  cout << ans << endl;
  return 0;
}