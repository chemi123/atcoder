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

// https://atcoder.jp/contests/abc196/tasks/abc196_c

int main() {
  ll n; cin >> n;
  int ans = 0;
  vector<ll> v{10, 100, 1000, 10000, 100000, 1000000};
  for (auto e : v) {
    bool ok = true;
    reps (i, e / 10, e) {
      ll num = i * e + i;
      if (num > n) {
        ok = false;
        break;
      }
      ++ans;
    }
    if (!ok) break;
  }
  cout << ans << endl;
  return 0;
}
