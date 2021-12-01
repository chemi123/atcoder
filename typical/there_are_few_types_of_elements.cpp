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

// https://atcoder.jp/contests/typical90/tasks/typical90_ah

int main() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  rep (i, n) cin >> a[i];
  unordered_map<int, int> m;
  int ans = 0;
  int l = 0;
  rep (r, n) {
    ++m[a[r]];
    while ((int)m.size() > k) {
      --m[a[l]];
      if (m[a[l]] == 0) m.erase(a[l]);
      ++l;
    }
    ans = max(ans, r - l + 1);
  }
  cout << ans << endl;
  return 0;
}