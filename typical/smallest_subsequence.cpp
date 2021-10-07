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

// https://atcoder.jp/contests/typical90/tasks/typical90_f

int main() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  vector c(n + 1, vector<int>(26, -1));
  for (int i = n - 1; i >= 0; --i) {
    rep (j, 26) {
      if ((int)(s[i] - 'a') == j) c[i][j] = i;
      else c[i][j] = c[i+1][j];
    }
  }

  string ans;
  int current = 0;
  rep (i, k) {
      rep (j, 26) {
      int pos = c[current][j];
      if (pos == -1) continue;
      if (n - pos >= k - i) {
        ans += 'a' + j;
        current = pos + 1;
        break;
      }
    }
  }
  cout << ans << endl;

  return 0;
}