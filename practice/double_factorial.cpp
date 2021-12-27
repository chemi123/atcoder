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

// https://atcoder.jp/contests/abc148/tasks/abc148_e

int main() {
  ll n; cin >> n;
  if (n % 2 == 1) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 0;
  n /= 2;
  while (n) {
    ans += n / 5;
    n /= 5;
  }
  cout << ans << endl;
  return 0;
}