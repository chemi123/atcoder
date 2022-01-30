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

int main() {
  ll x; cin >> x;
  set<ll> s;
  reps (i, 1, 10) reps (diff, -9, 10) {
    rep (digit, 18) {
      string numStr = to_string(i);
      rep (j, digit) {
        int next = (numStr.back() - '0') + diff;
        if (next < 0 || next >= 10) break;
        numStr += to_string(next);
      }
      s.emplace(stoll(numStr));
    }
  }
  cout << *s.lower_bound(x) << endl;
  return 0;
}