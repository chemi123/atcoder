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

// https://atcoder.jp/contests/abc127/tasks/abc127_c

int main() {
  int n, m; cin >> n >> m;
  int L = 1, R = n;
  rep (i, m) {
    int l, r; cin >> l >> r;
    L = max(L, l);
    R = min(R, r);
  }
  cout << max(0, R - L + 1) << endl;
  return 0;
}
