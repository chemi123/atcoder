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

// https://atcoder.jp/contests/abc241/tasks/abc241_d

int main() {
  int q; cin >> q;
  multiset<ll> s;
  s.emplace(-1);
  while (q--) {
    int type; cin >> type;
    ll x; cin >> x;
    if (type == 1) {
      s.emplace(x);
      continue;
    }

    int k; cin >> k;
    if (type == 2) {
      auto it = s.upper_bound(x);
      rep (i, k) {
        if (it == s.begin()) break;
        --it;
      }
      if (it == s.begin()) cout << -1 << endl;
      else cout << *it << endl;
    } else {
      auto it = s.lower_bound(x);
      rep (i, k - 1) {
        if (it == s.end()) break;
        ++it;
      }
      if (it == s.end()) cout << -1 << endl;
      else cout << *it << endl;
    }
  }
  return 0;
}