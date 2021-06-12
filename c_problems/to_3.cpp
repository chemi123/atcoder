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

// https://atcoder.jp/contests/abc182/tasks/abc182_c

int main() {
  string n; cin >> n;
  int ans = INF;
  rep (bits, 1 << n.size()) {
    int sum = 0;
    string tmp = n;
    rep (i, n.size()) {
      if (bits >> i & 1) sum += (tmp.back() - '0');
      tmp.pop_back();
    }
    if (sum > 0 && sum % 3 == 0) ans = min(ans, (int)n.size() - (int)bitset<18>(bits).count());
  }
  if (ans == INF) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}
