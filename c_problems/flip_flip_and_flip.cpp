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

// https://atcoder.jp/contests/abc090/tasks/arc091_a

int main() {
  ll n, m; cin >> n >> m;
  if (n == 1 && m == 1) {
    cout << 1 << endl;
    return 0;
  }

  if (n == 1) {
    cout << m - 2 << endl;
    return 0;
  }

  if (m == 1) {
    cout << n - 2 << endl;
    return 0;
  }

  cout << n * m - (n - 2) * 2 - (m - 2) * 2 - 4 << endl;
  return 0;
}