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

// https://atcoder.jp/contests/abc108/tasks/arc102_a

int main() {
  int n, k; cin >> n >> k;
  vector<ll> v(k);
  reps (i, 1, n + 1) ++v[i%k];
  ll ans = v[0] * v[0] * v[0];
  if (k % 2 == 0) ans += v[k/2] * v[k/2] * v[k/2];
  cout << ans << endl;
  return 0;
}
