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

// https://atcoder.jp/contests/abc246/tasks/abc246_d

int main() {
  long double n; cin >> n;
  auto f = [](ll a, ll b) {
    return a * a * a + a * a * b + a * b * b + b * b * b;
  };

  ll x = 2 * INFL;
  rep (a, 1e6 + 1) {
    ll ok = 1e6, ng = -1;
    while (abs(ok - ng) > 1) {
      ll mid = (ok + ng) / 2;
      if (f(a, mid) >= n) ok = mid;
      else ng = mid;
    }
    x = min(x, f(a, ok));
  }
  cout << x << endl;
  return 0;
}