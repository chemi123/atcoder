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

// https://atcoder.jp/contests/abc057/tasks/abc057_c

int main() {
  ll n; cin >> n;
  vector<ll> prime;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i != 0) continue;
    prime.emplace_back(i);
  }

  auto f = [](ll a, ll b) {
    string astr = to_string(a), bstr = to_string(b);
    return max((int)astr.size(), (int)bstr.size());
  };
  int ans = INF;
  for (auto a : prime) ans = min(ans, f(a, n / a));
  cout << ans << endl;
  return 0;
}