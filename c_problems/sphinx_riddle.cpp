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

// https://atcoder.jp/contests/abc006/tasks/abc006_3

int main() {
  int n, m; cin >> n >> m;
  rep (c, n + 1) {
    int a = -m + 3 * n + c;
    int b = m - 2 * n - 2 * c;
    if (a >= 0 && b >= 0) {
      cout << a << " " << b << " " << c << endl;
      return 0;
    }
  }
  cout << -1 << " " << -1 << " " << -1 << endl;
  return 0;
}
