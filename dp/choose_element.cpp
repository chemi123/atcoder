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

// https://atcoder.jp/contests/abc245/tasks/abc245_c

int main() {
  int n, k; cin >> n >> k;
  vector<int> a(n), b(n);
  rep (i, n) cin >> a[i];
  rep (i, n) cin >> b[i];
  vector<int> dp{a[0], b[0]};
  reps (i, 1, n) {
    vector<int> dp2(2, -1);
    for (auto e : dp) if (e != -1) {
      if (abs(a[i] - e) <= k) dp2[0] = a[i];
      if (abs(b[i] - e) <= k) dp2[1] = b[i];
    }
    if (dp2[0] == -1 && dp2[1] == -1) {
      cout << "No" << endl;
      return 0;
    }
    swap(dp, dp2);
  }
  cout << "Yes" << endl;
  return 0;
}