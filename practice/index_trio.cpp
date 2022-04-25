#include <algorithm>
#include <bitset>
#include <cassert>
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

// https://atcoder.jp/contests/abc249/tasks/abc249_d

void enumerateDivisor(set<ll>& s, ll n) {
  for (int i = 1; i * i <= n; ++i) {
    if (n % i != 0) continue;
    s.emplace(i);
    if (i * i != n) s.emplace(n/i);
  }
}

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  vector<ll> cnt(2 * 1e5 + 1);
  rep (i, n) {
    cin >> a[i];
    ++cnt[a[i]];
  }
  ll ans = 0;
  rep (i, n) {
    ll ai = a[i];
    set<ll> s;
    enumerateDivisor(s, ai);
    for (auto aj : s) {
      ll ak = ai / aj;
      ans += cnt[aj] * cnt[ak];
    }
  }
  cout << ans << endl;
  return 0;
}