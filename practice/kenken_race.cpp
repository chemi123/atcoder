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

// https://atcoder.jp/contests/agc034/tasks/agc034_a

int main() {
  int n, a, b, c, d; cin >> n >> a >> b >> c >> d; --a, --b, --c, --d;
  string s; cin >> s;
  if (c > d) {
    bool ok = false;
    reps (i, b - 1, d) if (s[i] == '.' && s[i+1] == '.' && s[i+2] == '.') {
      ok = true;
      break;
    }
    if (!ok) {
      cout << "No" << endl;
      return 0;
    }
  }

  int p = a;
  while (1) {
    if (p + 1 == c || p + 2 == c) {
      break;
    }
    if (s[p+1] == '#' && s[p+2] == '#') {
      cout << "No" << endl;
      return 0;
    }
    if (s[p+2] == '.') {
      p += 2;
      continue;
    }
    ++p;
  }
  p = b;
  while (1) {
    if (p + 1 == d || p + 2 == d) {
      break;
    }
    if (s[p+1] == '#' && s[p+2] == '#') {
      cout << "No" << endl;
      return 0;
    }
    if (s[p+2] == '.') {
      p += 2;
      continue;
    }
    ++p;
  }
  cout << "Yes" << endl;
  return 0;
}