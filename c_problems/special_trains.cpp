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

// https://atcoder.jp/contests/abc084/tasks/abc084_c

int main() {
  int n; cin >> n;
  vector<int> c(n - 1), s(n - 1), f(n - 1);
  rep (i, n - 1) cin >> c[i] >> s[i] >> f[i];

  rep (i, n - 1) {
    int ans = s[i] + c[i];
    reps (j, i + 1, n - 1) {
      while (ans % f[j] != 0) ++ans;
      if (ans < s[j]) ans = s[j];
      ans += c[j];
    }
    cout << ans << endl;
  }
  cout << 0 << endl;
  return 0;
}