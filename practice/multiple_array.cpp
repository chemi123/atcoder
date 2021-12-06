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

// https://atcoder.jp/contests/agc009/tasks/agc009_a

int main() {
  int n; cin >> n;
  vector<ll> a(n), b(n);
  rep (i, n) cin >> a[i] >> b[i];
  ll ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    a[i] += ans;
    if (a[i] % b[i] == 0) continue;
    ll t = a[i] / b[i] + 1;
    ans += (b[i] * t - a[i]);
  }
  cout << ans << endl;
  return 0;
}