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

// https://atcoder.jp/contests/abc091/tasks/arc092_a

int main() {
  int n; cin >> n;
  vector<pi> ab(n), cd(n);
  rep (i, n) cin >> ab[i].first >> ab[i].second;
  rep (i, n) cin >> cd[i].first >> cd[i].second;
  sort(ab.rbegin(), ab.rend());
  sort(cd.rbegin(), cd.rend());
  int ans = 0;
  int cdIndex = 0;
  multiset<int> s;
  rep (i, n) {
    auto [a, b] = ab[i];
    while (cdIndex < n && cd[cdIndex].first >= a) {
      s.emplace(cd[cdIndex].second);
      ++cdIndex;
    }
    auto it = s.lower_bound(b);
    if (it != s.end()) {
      ++ans;
      s.erase(it);
    }
  }
  cout << ans << endl;
  return 0;
}