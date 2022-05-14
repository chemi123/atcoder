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

// https://atcoder.jp/contests/abc127/tasks/abc127_d

int main() {
  int n, m; cin >> n >> m;
  map<ll, int> mp;
  rep (i, n) {
    ll a; cin >> a;
    ++mp[a];
  }
  while (m--) {
    int b; cin >> b;
    ll c; cin >> c;
    vector<int> del_list;
    for (auto& [num, cnt] : mp) {
      if (num >= c) break;
      if (b >= cnt) {
        mp[c] += cnt;
        b -= cnt;
        cnt = 0;
        del_list.emplace_back(num);
      } else {
        mp[c] += b;
        cnt -= b;
        b = 0;
      }

      if (!b) break;
    }
    for (auto e : del_list) mp.erase(e);
  }
  ll ans = 0;
  for (auto [num, cnt] : mp) ans += num * cnt;
  cout << ans << endl;
  return 0;
}