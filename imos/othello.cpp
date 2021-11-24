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

// https://atcoder.jp/contests/abc035/tasks/abc035_c

int main() {
  int n, q; cin >> n >> q;
  vector<int> v(n + 1);
  rep (i, q) {
    int l, r; cin >> l >> r; --l, --r;
    ++v[l];
    --v[r+1];
  }
  reps (i, 1, n + 1) v[i] += v[i-1];
  stringstream ss;
  rep (i, n) {
    if (v[i] % 2 == 0) ss << "0";
    else ss << "1";
  }
  cout << ss.str() << endl;
  return 0;
}