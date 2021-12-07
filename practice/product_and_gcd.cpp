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

// https://atcoder.jp/contests/caddi2018/tasks/caddi2018_a

void primeFactrization(map<ll, ll>& m, ll p) {
  for (ll i = 2; i * i <= p; ++i) {
    if (p % i != 0) continue;
    ll cnt = 0;
    while (p % i == 0) {
      ++cnt;
      p /= i;
    }
    m[i] = cnt;
  }
  if (p != 1) m[p] = 1;
}

int main() {
  ll n, p; cin >> n >> p;
  map<ll, ll> m;
  primeFactrization(m, p);
  ll ans = 1;
  for (auto& [prime, num] : m) {
    ll d = num / n;
    if (d > 0) ans *= pow(prime, d);
  }
  cout << ans << endl;
  return 0;
}