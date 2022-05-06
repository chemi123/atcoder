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

// https://atcoder.jp/contests/abc121/tasks/abc121_d

int main() {
  ll a, b; cin >> a >> b;
  ll ans = 0;
  if (b - a + 1 <= 10000) {
    for (ll i = a; i <= b; ++i) ans ^= i;
    cout << ans << endl;
    return 0;
  }
  if (a % 2 == 1) {
    ans = a;
    ++a;
  }
  if (b % 2 == 0) {
    ans ^= b;
    --b;
  }
  if (((b - a + 1) / 2) % 2 == 1) ans ^= 1;
  cout << ans << endl;
  return 0;
}