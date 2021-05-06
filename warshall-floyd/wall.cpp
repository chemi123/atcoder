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

// https://atcoder.jp/contests/abc079/tasks/abc079_d

int main() {
  int h, w; cin >> h >> w;
  vector<vector<int>> c(10, vector<int>(10, 0));
  rep (i, 10) rep (j, 10) cin >> c[i][j];
  vector<vector<int>> wall(h, vector<int>(w, 0));
  rep (i, h) rep (j, w) cin >> wall[i][j];
  rep (via, 10) {
    rep (from, 10) {
      rep (to, 10) {
        c[from][to] = min(c[from][to], c[from][via] + c[via][to]);
      }
    }
  }
  int ans = 0;
  for (auto& vec : wall) {
    for (auto e : vec) {
      if (e == -1 || e == 1) continue;
      ans += c[e][1];
    }
  }
  cout << ans << endl;
  return 0;
}