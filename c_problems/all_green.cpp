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

// https://atcoder.jp/contests/abc104/tasks/abc104_c

int main() {
  int d, g; cin >> d >> g;
  vector<pi> pc(d);
  rep (i, d) {
    int p, c; cin >> p >> c;
    pc[i] = pi(p, c);
  }
  reverse(pc.begin(), pc.end());

  int ans = INF;
  rep (i, 1 << d) {
    vector<bool> comp(d);
    rep (j, d) if (i >> j & 1) comp[j] = true;

    int sum = 0, cnt = 0;

    rep (j, d) {
      if (!comp[j]) continue;
      auto [p, c] = pc[j];
      int point = (d - j) * 100;
      sum += (point * p + c);
      cnt += p;
    }

    if (sum >= g) {
      ans = min(ans, cnt);
      continue;
    }

    rep (j, d) {
      if (comp[j]) continue;
      auto [p, _] = pc[j];
      --p;
      int point = (d - j) * 100;
      if (point * p + sum >= g) {
        int k = 1;
        for (; k < p; ++k) if (point * k + sum >= g) break;
        sum += point * k;
        cnt += k;
        break;
      } else {
        sum += point * p;
        cnt += p;
      }
    }

    if (sum >= g) ans = min(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}
