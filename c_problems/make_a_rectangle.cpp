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

// https://atcoder.jp/contests/abc071/tasks/arc081_a

int main() {
  int n; cin >> n;
  map<ll, ll, greater<ll>> m;
  rep (i, n) {
    int a; cin >> a;
    ++m[a];
  }

  ll s = 0;
  for (auto [l, num] : m) {
    if (s == 0 && num >= 4) {
      cout << l * l << endl;
      return 0;
    }
    if (s == 0 && num >= 2) {
      s = l;
      continue;
    }
    if (s != 0 && num >= 2) {
      cout << s * l << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}