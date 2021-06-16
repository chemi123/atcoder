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

// https://atcoder.jp/contests/abc175/tasks/abc175_c

int main() {
  ll x, k, d; cin >> x >> k >> d;
  if (x < 0) x = -x;
  ll num = x / d;
  if (k <= num) {
    cout << x - k * d << endl;
    return 0;
  }

  x = x - num * d;
  k -= num;
  if (k % 2 == 0) cout << x << endl;
  else cout << d - x << endl;
  return 0;
}
