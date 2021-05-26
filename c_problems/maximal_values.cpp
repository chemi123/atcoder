#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

// https://atcoder.jp/contests/abc140/tasks/abc140_c

int main() {
  int n; cin >> n;
  vector<int> b(n-1);
  rep (i, n) cin >> b[i];
  int ans = b[0];
  ans += b[n-2];
  reps (i, 1, n - 1) ans += min(b[i-1], b[i]);
  cout << ans << endl;
  return 0;
}
