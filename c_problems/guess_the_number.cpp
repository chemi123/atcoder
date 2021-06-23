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

// https://atcoder.jp/contests/abc157/tasks/abc157_c

int main() {
  int n, m; cin >> n >> m;
  vector<int> s(m), c(m);
  rep (i, m) {
    cin >> s[i] >> c[i];
    --s[i];
  }
  int from = 0, to = 10;
  if (n == 2) from = 10, to = 100;
  else if (n == 3) from = 100, to = 1000;
  reps (num, from, to) {
    bool ok = true;
    string numStr = to_string(num);
    rep (i, m) {
      if (numStr[s[i]] - '0' != c[i]) {
        ok = false;
        break;
      }
    }

    if (ok) {
      cout << num << endl;
      break;
    }
    if (!ok && num == to - 1) {
      cout << -1 << endl;
    }
  }
  return 0;
}
