#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
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

// https://atcoder.jp/contests/abc126/tasks/abc126_c

int main() {
  long double n, k; cin >> n >> k;
  long double ans = 0;
  for (long double a = 1; a <= n; ++a) {
    if (a >= k) {
      ans += (long double)1 / n;
      continue;
    }
    long double b = ceil(log2(k / a));
    ans += ((long double)1 / pow(2, b)) * ((long double)1 / n);
  }
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}
