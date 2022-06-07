#include <algorithm>
#include <bitset>
#include <cassert>
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

// 良解説
// https://note.com/cell_tower_theta/n/nbb46326458da
// https://atcoder.jp/contests/abc254/tasks/abc254_d

int main() {
  ll n; cin >> n;
  ll ans = 0;
  for (ll i = 1; i <= n; ++i) {
    ll k = i;
    for (ll j = 2; j * j <= k; ++j) {
      while (k % (j * j) == 0) k /= (j * j);
    }
    for (ll j = 1; k * (j * j) <= n; ++j) ++ans;
  }
  cout << ans << endl;
  return 0;
}