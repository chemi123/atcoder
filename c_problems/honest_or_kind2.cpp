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

// https://atcoder.jp/contests/abc147/tasks/abc147_c

int main() {
  int n; cin >> n;
  vector<vector<pi>> claim(n);
  rep (i, n) {
    int a; cin >> a;
    rep (j, a) {
      int x, y; cin >> x >> y; --x;
      claim[i].emplace_back(pi(x, y));
    }
  }

  int ans = 0;
  rep (i, 1 << n) {
    vector<bool> honest(n);
    int cnt = 0;
    rep (bit, n) if (i >> bit & 1) {
      honest[bit] = true;
      ++cnt;
    }

    bool ok = true;
    rep (j, n) {
      if (!honest[j]) continue;
      for (auto [f, s] : claim[j]) {
        if (s == 1 && !honest[f]) ok = false;
        if (s == 0 && honest[f]) ok = false;
      }
    }

    if (ok) ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}
