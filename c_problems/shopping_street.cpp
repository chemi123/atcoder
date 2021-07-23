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

// https://atcoder.jp/contests/abc080/tasks/abc080_c

int main() {
  int n; cin >> n;
  vector<vector<int>> f(n, vector<int>(10));
  vector<vector<int>> p(n, vector<int>(11));
  rep (i, n) rep (j, 10) cin >> f[i][j];
  rep (i, n) rep (j, 11) cin >> p[i][j];

  int ans = -INF;
  reps (i, 1, 1 << 10) {
    vector<int> bit(10);
    rep (j, 10) if (i >> j & 1) bit[j] = 1;

    int profit = 0;
    rep (j, n) {
      int cnt = 0;
      rep (k, 10) if (bit[k] && f[j][k]) ++cnt;
      profit += p[j][cnt];
    }

    ans = max(ans, profit);
  }
  cout << ans << endl;

  return 0;
}