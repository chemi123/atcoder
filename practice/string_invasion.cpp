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

// https://atcoder.jp/contests/arc113/tasks/arc113_c

int main() {
  string s; cin >> s;
  int n = s.size();
  stack<int> stk;
  char current = '0';
  ll cnt = 0;
  rep (i, n) {
    if (s[i] == current) {
      ++cnt;
      continue;
    }
    if (i < n - 1 && s[i] == s[i+1] && s[i] != current) {
      current = s[i];
      stk.push(i);
      ++i;
    }
  }
  ll ans = 0;
  while (!stk.empty()) {
    ans += n - stk.top() - 2;
    stk.pop();
  }
  cout << ans - cnt << endl;
  return 0;
}