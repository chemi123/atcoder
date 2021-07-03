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

// https://atcoder.jp/contests/abc120/tasks/abc120_c

int main() {
  stack<int> s;
  string str; cin >> str;
  int ans = 0;
  rep (i, str.size()) {
    if (s.empty() || s.top() == str[i]) s.emplace(str[i]);
    else {
      ans += 2;
      s.pop();
    }
  }
  cout << ans << endl;
  return 0;
}
