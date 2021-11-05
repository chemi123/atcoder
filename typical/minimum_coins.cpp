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

// https://atcoder.jp/contests/typical90/tasks/typical90_p

int main() {
  int n; cin >> n;
  vector<int> abc(3);
  cin >> abc[0] >> abc[1] >> abc[2];
  sort(abc.begin(), abc.end(), greater<int>());
  ll a = abc[0], b = abc[1], c = abc[2];
  ll ans = INF;
  for (ll i = 9999; i >= 0; --i) {
    if (a * i > n) continue;
    for (ll j = 9999 - i; j >= 0; --j) {
      ll rest = n - a * i - b * j;
      if (rest < 0) continue;
      if (rest % c == 0) ans = min(ans, i + j + rest / c);
    }
  }
  cout << ans << endl;
  return 0;
}