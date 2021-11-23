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

// https://atcoder.jp/contests/typical90/tasks/typical90_x

int main() {
  int n, k; cin >> n >> k;
  vector<int> a(n), b(n);
  rep (i, n) cin >> a[i];
  rep (i, n) cin >> b[i];
  rep (i, n) k -= abs(a[i] - b[i]);
  if (k >= 0 && k % 2 == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}