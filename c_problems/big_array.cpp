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

// https://atcoder.jp/contests/abc061/tasks/abc061_c

int main() {
  ll n, k; cin >> n >> k;
  map<ll, ll> m;
  rep (i, n) {
    ll a, b; cin >> a >> b;
    m[a] += b;
  }

  for (auto [num, cnt] : m) {
    if (k <= cnt) {
      cout << num << endl;
      break;
    }
    k -= cnt;
  }
  return 0;
}