#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

// https://atcoder.jp/contests/abc066/tasks/arc077_a

int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep (i, n) cin >> a[i];

  if (n % 2 == 0) {
    for (int i = n - 1; i >= 0; i -= 2) cout << a[i] << " ";
    for (int i = 0; i < n; i += 2) cout << a[i] << " "; cout << endl;
  } else {
    for (int i = n - 1; i >= 0; i -= 2) cout << a[i] << " ";
    for (int i = 1; i < n; i += 2) cout << a[i] << " "; cout << endl;
  }
  return 0;
}