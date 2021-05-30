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

// ユークリッドの互助法を使った解法
// https://atcoder.jp/contests/abc118/tasks/abc118_c

int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep (i, n) cin >> a[i];
  int res = 0;
  for (auto e : a) res = gcd(res, e);
  cout << res << endl;
  return 0;
}

