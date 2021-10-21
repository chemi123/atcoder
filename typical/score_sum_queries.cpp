#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
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

// https://atcoder.jp/contests/typical90/tasks/typical90_j

int main() {
  int n; cin >> n;
  vector<int> acc1(n), acc2(n);
  rep (i, n) {
    int c, p; cin >> c >> p;
    if (c == 1) acc1[i] += p;
    else acc2[i] += p;
    if (i > 0) {
      acc1[i] += acc1[i-1];
      acc2[i] += acc2[i-1];
    }
  }
  int q; cin >> q;
  rep (i, q) {
    int l, r; cin >> l >> r; --l, --r;
    if (l == 0) cout << acc1[r] << " " << acc2[r] << endl;
    else cout << acc1[r] - acc1[l-1] << " " << acc2[r] - acc2[l-1] << endl;
  }
  return 0;
}