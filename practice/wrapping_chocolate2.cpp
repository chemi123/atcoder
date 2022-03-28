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

// https://atcoder.jp/contests/abc245/tasks/abc245_e

int main() {
  int n, m; cin >> n >> m;
  vector<pi> ab(n), cd(m);
  rep (i, n) cin >> ab[i].first;
  rep (i, n) cin >> ab[i].second;
  rep (i, m) cin >> cd[i].first;
  rep (i, m) cin >> cd[i].second;
  sort(ab.rbegin(), ab.rend());
  sort(cd.rbegin(), cd.rend());
  int cdIndex = 0;
  multiset<int> s;
  rep (i, n) {
    auto [x, y] = ab[i];
    while (cdIndex < m && cd[cdIndex].first >= x) {
      s.emplace(cd[cdIndex].second);
      ++cdIndex;
    }
    auto it = s.lower_bound(y);
    if (it == s.end()) {
      cout << "No" << endl;
      return 0;
    }

    s.erase(it);
  }
  cout << "Yes" << endl;
  return 0;
}