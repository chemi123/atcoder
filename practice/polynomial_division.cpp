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

// https://atcoder.jp/contests/abc245/tasks/abc245_d

int main() {
  int n, m; cin >> n >> m;
  vector<int> a(n + 1), b(m + 1), c(n + m + 1);
  rep (i, n + 1) cin >> a[i];
  rep (i, n + m + 1) cin >> c[i];
  for (int i = m; i >= 0; --i) {
    b[i] = c[n+i] / a[n];
    for (int j = n; j >= 0; --j) {
      c[i+j] -= b[i] * a[j];
    }
  }
  for (auto e : b) cout << e << " "; cout << endl;
  return 0;
}