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

// https://atcoder.jp/contests/abc243/tasks/abc243_d

int main() {
  int n; cin >> n;
  ll x; cin >> x;
  string s; cin >> s;
  vector<char> v;
  v.reserve(n);
  rep (i, n) {
    if (v.size() == 0) {
      v.emplace_back(s[i]);
      continue;
    }
    if (s[i] == 'U') {
      if (v.back() == 'U') v.emplace_back(s[i]);
      else v.pop_back();
    } else v.emplace_back(s[i]);
  }
  n = (int)v.size();
  rep (i, n) {
    if (v[i] == 'U') x /= 2;
    else if (v[i] == 'L') x *= 2;
    else x = x * 2 + 1;
  }
  cout << x << endl;
  return 0;
}