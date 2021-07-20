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

// https://atcoder.jp/contests/abc086/tasks/arc089_a

int main() {
  int n; cin >> n;
  int cx = 0, cy = 0, ct = 0;
  rep (i, n) {
    int t, x, y; cin >> t >> x >> y;
    int l = abs(x - cx) + abs(y - cy);
    int limit = t - ct;
    if (limit < l) {
      cout << "No" << endl;
      return 0;
    }

    if (limit % 2 != l % 2) {
      cout << "No" << endl;
      return 0;
    }

    ct = t, cx = x, cy = y;
  }

  cout << "Yes" << endl;
  return 0;
}