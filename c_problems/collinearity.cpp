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
using pd = pair<long double, long double>;

const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1000000007;

// https://atcoder.jp/contests/abc181/tasks/abc181_c

int main() {
  int n; cin >> n;
  vector<pd> point(n);
  rep (i, n) {
    long double x, y; cin >> x >> y;
    point[i] = pi(x, y);
  }
  rep (i, n) {
    reps (j, i + 1, n) {
      reps (k, j + 1, n) {
        auto [x1, y1] = point[i];
        auto [x2, y2] = point[j];
        auto [x3, y3] = point[k];
        if (x1 == x2) {
          if (x3 == x1) {
            cout << "Yes" << endl;
            return 0;
          }
          continue;
        }
        if (((y2 - y1) / (x2 - x1)) * x3 + ((y2 - y1) / (x2 - x1)) * (0 - x1) + y1 == y3) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
