#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

// https://atcoder.jp/contests/abc065/tasks/arc076_a

int main() {
  ll n, m; cin >> n >> m;
  if (abs(n - m) >= 2) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = (n == m) ? 2 : 1;
  reps (i, 1, n + 1) ans = ans * i % MOD;
  reps (i, 1, m + 1) ans = ans * i % MOD;
  cout << ans << endl;

  return 0;
}