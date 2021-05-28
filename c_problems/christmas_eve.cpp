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

// https://atcoder.jp/contests/abc115/tasks/abc115_c

int main() {
  int n, k; cin >> n >> k;
  vector<int> h(n);
  rep (i, n) cin >> h[i];
  sort(h.begin(), h.end());
  int ans = INF;
  reps (r, k - 1, n) {
    int l = r - k + 1;
    ans = min(ans, h[r] - h[l]);
  }
  cout << ans << endl;
  return 0;
}
