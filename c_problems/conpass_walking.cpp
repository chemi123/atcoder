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

int main() {
  double r, x, y; cin >> r >> x >> y;
  double l = sqrt(x * x + y * y);
  if (r > l) {
    cout << 2 << endl;
    return 0;
  }
  if ((l / r) - floor(l / r) > 0) cout << floor(l / r) + 1 << endl;
  else cout << l / r << endl;
  return 0;
}