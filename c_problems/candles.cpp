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

// https://atcoder.jp/contests/abc107/tasks/arc101_a

int main() {
  int n, k; cin >> n >> k;
  vector<int> x(n);
  rep (i, n) cin >> x[i];
  int ans = INF;
  rep (i, n - k + 1) {
    int l = x[i], r = x[i+k-1];
    if (r <= 0) ans = min(ans, -l);
    else if (l >= 0) ans = min(ans, r);
    else if (l < 0 && r > 0) {
      if (-l >= r) ans = min(ans, -l + r * 2);
      else ans = min(ans, -l * 2 + r);
    }
  }
  cout << ans << endl;
  return 0;
}