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

// https://atcoder.jp/contests/abc162/tasks/abc162_d

int main() {
  int n; cin >> n;
  string s; cin >> s;
  ll r = 0, g = 0, b = 0;
  rep (i, n) {
    if (s[i] == 'R') ++r;
    else if (s[i] == 'G') ++g;
    else ++b;
  }
  ll ans = r * g * b;
  for (int l = 1; 2 * l <= n; ++l) {
    rep (i, n) {
      int j = i + l;
      int k = j + l;
      if (k >= n) break;
      if (s[i] != s[j] && s[i] != s[k] && s[j] != s[k]) --ans;
    }
  }
  cout << ans << endl;
  return 0;
}