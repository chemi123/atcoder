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

// https://atcoder.jp/contests/abc171/tasks/abc171_d

int main() {
  int n; cin >> n;
  map<ll, ll> m;
  ll ans = 0;
  rep (i, n) {
    ll a; cin >> a;
    ++m[a];
    ans += a;
  }
  int q; cin >> q;
  rep (i, q) {
    ll b, c; cin >> b >> c;
    ans += (c * m[b] - b * m[b]);
    m[c] += m[b];
    m.erase(b);
    cout << ans << endl;
  }
  return 0;
}