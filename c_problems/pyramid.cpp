#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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
  int n; cin >> n;
  vector<int> x(n), y(n), h(n);
  rep (i, n) cin >> x[i] >> y[i] >> h[i];
  rep (cx, 101) {
    rep (cy, 101) {
      int H = -1;
      rep (i, n) if (h[i] > 0) H = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
      bool ok = true;
      rep (i, n) if (max(H - abs(x[i] - cx) - abs(y[i] - cy), 0) != h[i]) ok = false;
      if (ok) {
        cout << cx << " " << cy << " " << H << endl;
        return 0;
      }
    }
  }
  return 0;
}
