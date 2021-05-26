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

// https://atcoder.jp/contests/abc116/tasks/abc116_c

int main() {
  int n; cin >> n;
  vector<int> h(n);
  rep (i, n) cin >> h[i];
  int ans = 0;
  while (1) {
    bool ok = true, streak = false;
    rep (i, n) {
      if (streak && h[i] == 0) break;
      if (h[i] > 0) {
        if (!streak) {
          ok = false;
          streak = true;
          ++ans;
        }
        --h[i];
      }
    }
    if (ok) break;
  }
  cout << ans << endl;
  return 0;
}
