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

// https://atcoder.jp/contests/abc085/tasks/abc085_c

int main() {
  int n, y; cin >> n >> y;
  rep (c, n + 1) {
    int a = (-y + 5000 * n + 5000 * c);
    int b = (y - 1000 * n - 9000 * c);
    if (a >= 0 && a % 4000 == 0 && b >= 0 && b % 4000 == 0) {
      cout << c << " " << b / 4000 << " " << a / 4000 << endl;
      return 0;
    }
  }
  cout << "-1 -1 -1" << endl;
  return 0;
}