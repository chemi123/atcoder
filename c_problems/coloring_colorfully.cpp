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

// https://atcoder.jp/contests/abc124/tasks/abc124_c

int main() {
  string s; cin >> s;
  string tmp = s;
  int ans1 = 0, ans2 = 0;
  reps (i, 1, s.size()) {
    if (tmp[i] != tmp[i-1]) continue;
    if (tmp[i] == '0') tmp[i] = '1';
    else tmp[i] = '0';
    ++ans1;
  }

  tmp = s;
  for (int i = s.size() - 2; i >= 0; --i) {
    if (tmp[i] != tmp[i+1]) continue;
    if (tmp[i] == '0') tmp[i] = '1';
    else tmp[i] = '0';
    ++ans2;
  }
  cout << min(ans1, ans2) << endl;
  return 0;
}
