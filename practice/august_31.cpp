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

// https://atcoder.jp/contests/code-festival-2015-quala/tasks/codefestival_2015_qualA_c

int main() {
  ll n, t; cin >> n >> t;
  vector<pl> ab(n);
  ll total = 0;
  rep (i, n) {
    ll a, b; cin >> a >> b;
    ab[i] = pl(a, b);
    total += a;
  }
  sort(ab.begin(), ab.end(), [](const auto& l, const auto& r) { return l.first - l.second > r.first - r.second; });
  int ans = 0;
  rep (i, n) if (total > t) {
    ++ans;
    total -= (ab[i].first - ab[i].second);
  }
  if (total > t) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}