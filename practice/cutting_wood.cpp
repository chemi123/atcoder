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

// https://atcoder.jp/contests/abc217/tasks/abc217_d

int main() {
  int l, q; cin >> l >> q;
  set<int> s;
  s.emplace(0);
  s.emplace(l);
  while (q--) {
    int c, x; cin >> c >> x;
    if (c == 1) {
      s.emplace(x);
      continue;
    }
    auto it = s.lower_bound(x);
    int right = *it;
    --it;
    int left = *it;
    cout << right - left << endl;
  }
  return 0;
}