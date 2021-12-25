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

// https://atcoder.jp/contests/abc141/tasks/abc141_d

int main() {
  ll n, m; cin >> n >> m;
  map<ll, ll, greater<ll>> mp;
  rep (i, n) {
    ll a; cin >> a;
    ++mp[a];
  }
  rep (i, m) {
    auto it = mp.begin();
    ++mp[it->first/2];
    --it->second;
    if (it->second == 0) mp.erase(it->first);
  }
  ll ans = 0;
  for (auto [f, s] : mp) ans += (f * s);
  cout << ans << endl;
  return 0;
}