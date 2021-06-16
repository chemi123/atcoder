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
  int k; cin >> k;
  vector<bool> s(k);
  int a = 7;
  bool ok = true;
  int ans = 1;
  while (1) {
    if (s[a]) {
      ok = false;
      break;
    }
    if (a % k == 0) {
      cout << ans << endl;
      break;
    }
    s[a] = true;
    a = (a * 10 + 7) % k;
    ++ans;
  }
  if (!ok) cout << -1 << endl;
  return 0;
}
