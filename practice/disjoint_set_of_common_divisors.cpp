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

// https://atcoder.jp/contests/abc142/tasks/abc142_d

void enumeratePrimes(set<ll>& s, ll num) {
  for (ll i = 2; i * i <= num; ++i) {
    if (num % i != 0) continue;
    s.emplace(i);
    while (num % i == 0) num /= i;
  }

  if (num != 1) s.emplace(num);
}

int main() {
  ll a, b; cin >> a >> b;
  set<ll> ans;
  ans.emplace(1);
  enumeratePrimes(ans, gcd(a, b));
  cout << ans.size() << endl;
  return 0;
}