#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

// https://atcoder.jp/contests/abc089/tasks/abc089_c

int main() {
  int n; cin >> n;
  vector<ll> v(5);
  rep (i, n) {
    string s; cin >> s;
    if (s[0] == 'M') ++v[0];
    else if (s[0] == 'A') ++v[1];
    else if (s[0] == 'R') ++v[2];
    else if (s[0] == 'C') ++v[3];
    else if (s[0] == 'H') ++v[4];
  }

  ll ans = 0;
  rep (i, 5) reps (j, i + 1, 5) reps (k, j + 1, 5) ans += v[i] * v[j] * v[k];
  cout << ans << endl;
  return 0;
}