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

// https://atcoder.jp/contests/abc190/tasks/abc190_c

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> consts(m, vector<int>(2));
  rep (i, m) cin >> consts[i][0] >> consts[i][1];
  int k; cin >> k;
  vector<vector<int>> bowls(k, vector<int>(2));
  rep (i, k) cin >> bowls[i][0] >> bowls[i][1];

  int ans = 0;
  rep (i, 1 << k) {
    vector<int> dishes(n + 1);
    rep (j, k) {
      if (i >> j & 1) ++dishes[bowls[j][1]];
      else  ++dishes[bowls[j][0]];
    }
    int sum = 0;
    for (auto& c : consts) if (dishes[c[0]] > 0 && dishes[c[1]] > 0) ++sum;
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}