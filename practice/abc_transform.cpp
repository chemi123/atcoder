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

// https://atcoder.jp/contests/abc242/tasks/abc242_d

int main() {
  string s; cin >> s;
  int q; cin >> q;
  rep (i, q) {
    ll t, k; cin >> t >> k; --k;
    ll si = 0;
    ll r;
    if (t <= 60) {
      si = k >> t;
      ll mask = (1ll << t) - 1;
      r = __builtin_popcountll(k & mask);
    } else {
      r = __builtin_popcountll(k);
    }
    ll l = t - r;
    ll ans = (((s[si] - 'A') + l + r * 2) % 3) + 'A';
    cout << (char)ans << endl;
  }
  return 0;
}