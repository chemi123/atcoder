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

// https://atcoder.jp/contests/abc234/tasks/abc234_e

int main() {
  ll x; cin >> x;
  set<ll> ans;
  reps (i, 1, 10) reps (diff, -9, 9) {
    rep (digit, 18) {
      string s = to_string(i);
      rep (j, digit) {
        int next = (s.back() - '0') + diff;
        if (0 <= next && next < 10) s += to_string(next);
        else break;
      }
      ans.emplace(stoll(s));
    }
  }
  cout << *ans.lower_bound(x) << endl;
  return 0;
}