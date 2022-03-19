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

// https://atcoder.jp/contests/agc034/tasks/agc034_b

int main() {
  string s; cin >> s;
  int index = 0;
  ll ans = 0;
  int streaks = 0;
  while (index < (int)s.size() - 1) {
    if (s[index] == 'A') {
      ++streaks;
      ++index;
      continue;
    }

    if (s[index] == 'B' && s[index+1] == 'C') {
      ans += streaks;
      index += 2;
    } else {
      streaks = 0;
      ++index;
    }
  }
  cout << ans << endl;
  return 0;
}