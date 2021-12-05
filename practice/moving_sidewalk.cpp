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

// https://atcoder.jp/contests/arc054/tasks/arc054_a

int main() {
  long double l, x, y, s, d; cin >> l >> x >> y >> s >> d;
  long double ans = (double)INF;
  long double distance = 0;
  if (x < y) {
    if (d >= s) distance = s + l - d;
    else distance = s - d;
    ans = distance / (y - x);
  }
  if (d >= s) distance = d - s;
  else distance = l - s + d;
  ans = min(ans, distance / (x + y));
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}