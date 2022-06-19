#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
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

// https://atcoder.jp/contests/abc256/tasks/abc256_d

int main() {
  int n; cin >> n;
  vector<int> imos(2 * 1e5 + 1);
  while (n--) {
    int l, r; cin >> l >> r;
    ++imos[l], --imos[r];
  }
  reps (i, 1, imos.size()) imos[i] += imos[i-1];
  vector<pi> ans;
  int l = -1, r = -1;
  rep (i, imos.size()) {
    if (imos[i] > 0 && l == -1) {
      l = i;
    } else if (imos[i] > 0 && l != -1) {
      // 何もしないが、このケースもあることだけ明示的に示しておく
    } else if (imos[i] == 0 && l != -1) {
      r = i;
    }

    if (l != -1 && r != -1) {
      ans.emplace_back(pi(l, r));
      l = -1, r = -1;
    }
  }
  for (auto [l, r] : ans) cout << l << " " << r << endl;
  return 0;
}