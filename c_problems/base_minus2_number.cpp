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

// https://atcoder.jp/contests/abc105/tasks/abc105_c

int main() {
  int n; cin >> n;
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }

  stringstream ss;
  while (n != 0) {
    if (n < 0 && n % 2 != 0) {
      ss << 1;
      --n;
    } else {
      ss << n % (-2);
    }
    n /= (-2);
  }
  string ans = ss.str();
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
