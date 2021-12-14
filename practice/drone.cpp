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

// https://atcoder.jp/contests/abc035/tasks/abc035_b

int main() {
  string s; cin >> s;
  int t; cin >> t;
  int q = 0, x = 0, y = 0;
  rep (i, (int)s.size()) {
    if (s[i] == 'L') --x;
    else if (s[i] == 'R') ++x;
    else if (s[i] == 'U') ++y;
    else if (s[i] == 'D') --y;
    else ++q;
  }
  int ans = abs(x) + abs(y);
  if (t == 1) ans += q;
  else {
    if (ans >= q) ans -= q;
    else ans = (q - ans) % 2 == 0 ? 0 : 1;
  }
  cout << ans << endl;
  return 0;
}