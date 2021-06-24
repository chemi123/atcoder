#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
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

// https://atcoder.jp/contests/abc137/tasks/abc137_c

int main() {
  int n; cin >> n;
  unordered_map<string, ll> m;
  rep (i, n) {
    string s; cin >> s;
    sort(s.begin(), s.end());
    ++m[s];
  }
  ll ans = 0;
  for (auto [_, num] : m) ans += num * (num - 1) / 2;
  cout << ans << endl;
  return 0;
}
