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

// https://atcoder.jp/contests/abc197/tasks/abc197_c

int main() {
  ll n; cin >> n;
  vector<ll> a(n);
  rep (i, n) cin >> a[i];
  ll ans = INFL;
  for (ll bits = 0; bits < 1 << (n - 1); ++bits) {
    vector<bool> par(n-1);
    rep (i, n - 1) if (1 << i & bits) par[i] = true;
    ll score = 0;
    ll current = a[0];
    reps (i, 1, n) {
      if (par[i-1]) {
        score ^= current;
        current = a[i];
      } else {
        current |= a[i];
      }
    }
    score ^= current;
    ans = min(ans, score);
  }
  cout << ans << endl;
  return 0;
}