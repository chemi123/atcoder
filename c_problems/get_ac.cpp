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

// https://atcoder.jp/contests/abc122/tasks/abc122_c

int main() {
  int n, q; cin >> n >> q;
  string s; cin >> s;
  vector<int> acc(n);
  reps (i, 1, n) {
    acc[i] = acc[i-1];
    if (s.substr(i - 1, 2) == "AC") ++acc[i];
  }
  rep (i, q) {
    int l, r; cin >> l >> r; --l, --r;
    cout << acc[r] - acc[l] << endl;
  }
  return 0;
}
