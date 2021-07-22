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

// https://atcoder.jp/contests/abc078/tasks/arc085_a

int main() {
  double n, m; cin >> n >> m;
  double ans = 0;
  double sPos = pow((double)1 / 2, m);
  double fPos = 1 - sPos;
  reps (i, 1, 10001) ans += (1900 * m + 100 * (n - m)) * i * pow(fPos, i - 1) * sPos;
  cout << ans << endl;
  return 0;
}