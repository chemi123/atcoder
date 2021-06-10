#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
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

// https://atcoder.jp/contests/abc202/tasks/abc202_d

int main() {
  ll a, b, k; cin >> a >> b >> k;
  vector<vector<ll>> combi(61, vector<ll>(61));
  combi[0][0] = 1;
  rep (i, 60) {
    rep (j, i + 1) {
      combi[i+1][j] += combi[i][j];
      combi[i + 1][j + 1] += combi[i][j];
    }
  }
  string ans = "";
  while (a + b > 0) {
    if (a == 0) {
      ans += "b";
      --b;
      continue;
    }
    if (b == 0) {
      ans += "a";
      --a;
      continue;
    }
    if (combi[a+b-1][b] >= k) {
      ans += "a";
      --a;
    } else {
      ans += "b";
      k -= combi[a+b-1][b];
      --b;
    }
  }
  cout << ans << endl;
  return 0;
}
