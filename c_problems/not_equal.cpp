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

// https://atcoder.jp/contests/abc209/tasks/abc209_c

int main() {
  int n; cin >> n;
  vector<ll> c(n);
  rep (i, n) cin >> c[i];
  sort(c.begin(), c.end());
  ll ans = 1;
  rep (i, n) ans = ans * (c[i] - i) % MOD;
  cout << ans << endl;
  return 0;
}