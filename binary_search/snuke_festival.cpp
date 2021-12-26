#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

// https://atcoder.jp/contests/abc077/tasks/arc084_a

ll biggerSearch(const vector<int>& vec, int target) {
  ll ok = (ll)vec.size();
  ll ng = -1;
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (vec[mid] <= target) ng = mid;
    else ok = mid;
  }
  return ok;
}

ll lowerSearch(const vector<int>& vec, int target) {
  ll ok = -1;
  ll ng = (ll)vec.size();
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (vec[mid] >= target) ng = mid;
    else ok = mid;
  }
  return ok;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n, 0), b(n, 0), c(n, 0);
  rep (i, n) cin >> a[i];
  rep (i, n) cin >> b[i];
  rep (i, n) cin >> c[i];
  sort(a.begin(), a.end());
  sort(c.begin(), c.end());

  ll ans = 0;
  rep (i, n) {
    ll ai = lowerSearch(a, b[i]);
    ll ci = biggerSearch(c, b[i]);
    ans += ((ai + 1) * (n - ci));
  }
  cout << ans << endl;
  return 0;
}