#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <map>
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

// https://atcoder.jp/contests/abc195/tasks/abc195_d

int main() {
  int n, m, q; cin >> n >> m >> q;
  vector<pi> wv(n);
  rep (i, n) {
    int w, v; cin >> w >> v;
    wv[i] = pi(w, v);
  }

  vector<int> x(m);
  rep (i, m) cin >> x[i];

  while (q--) {
    int l, r; cin >> l >> r; --l, --r;
    vector<int> availableBox;
    rep (j, m) if (j < l || r < j) availableBox.emplace_back(x[j]);
    vector<bool> used(availableBox.size());
    sort(availableBox.begin(), availableBox.end());
    int ans = 0;
    rep (j, availableBox.size()) {
      // 価値, index
      pi candidate = pi(-1, -1);
      rep (i, n) if (!used[i]) {
        auto [w, v] = wv[i];
        if (availableBox[j] < w) continue;
        if (v > candidate.first) candidate = pi(v, i);
      }
      if (candidate.first != -1) {
        ans += candidate.first;
        used[candidate.second] = true;
      }
    }
    cout << ans << endl;
  }
  return 0;
}