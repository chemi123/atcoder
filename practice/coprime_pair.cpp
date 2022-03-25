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

// https://atcoder.jp/contests/arc137/tasks/arc137_a

int main() {
  ll l, r; cin >> l >> r;
  ll d = r - l;
  while (d) {
    for (ll i = l; i + d <= r; ++i) {
      ll j = i + d;
      if (gcd(i, j) == 1) {
        cout << j - i << endl;
        return 0;
      }
    }
    --d;
  }
  return 0;
}