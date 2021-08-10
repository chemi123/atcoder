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

// https://atcoder.jp/contests/abc052/tasks/arc067_a

void enumeratePrime(map<int, int>& m, int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i != 0) continue;
    int cnt = 0;
    while (n % i == 0) {
      ++cnt;
      n /= i;
    }
    m[i] += cnt;
  }
  if (n != 1) m[n] += 1;
}

int main() {
  int n; cin >> n;
  map<int, int> m;

  reps (i, 2, n + 1) enumeratePrime(m, i);

  ll ans = 1;
  for (auto [_, cnt] : m) {
    ans *= (cnt + 1);
    ans = ans % MOD;
  }
  cout << ans << endl;
  return 0;
}