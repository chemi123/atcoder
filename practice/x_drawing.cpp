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

// https://atcoder.jp/contests/abc230/tasks/abc230_c

int main() {
  ll n, a, b; cin >> n >> a >> b;
  ll p, q, r, s; cin >> p >> q >> r >> s;

  for (ll x = p; x <= q; ++x) {
    string line;
    line.reserve(q - p + 1);
    for (ll y = r; y <= s; ++y) {
      if ((x - y == a - b || x + y == a + b)) line += "#";
      else line += ".";
    }
    cout << line << endl;
  }
  return 0;
}