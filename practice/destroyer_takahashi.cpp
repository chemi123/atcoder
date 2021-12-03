#include <algorithm>
#include <bitset>
#include <cmath>
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

// https://atcoder.jp/contests/abc230/tasks/abc230_d

int main() {
  ll n, d; cin >> n >> d;
  vector<pair<ll, ll>> lr(n);
  rep (i, n) {
    ll l, r; cin >> l >> r;
    lr[i] = pair<ll, ll>(l, r);
  }
  sort(lr.begin(), lr.end(), [](const auto &l, const auto &r) { return l.second < r.second; });
  int ans = 0;
  rep (i, n) {
    if (lr[i].first == 0) continue;
    lr[i].first = 0;
    ++ans;
    ll left = lr[i].second, right = left + d - 1;
    reps (j, i + 1, n) {
      if (lr[j].first <= lr[i].second) {
        lr[j].first = 0;
        continue;
      }
      if (lr[j].first <= right) {
        lr[j].first = 0;
        continue;
      }
      break;
    }
  }
  cout << ans << endl;
  return 0;
}