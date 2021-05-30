#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

// https://atcoder.jp/contests/abc113/tasks/abc113_c

int main() {
  int n, m; cin >> n >> m;
  unordered_map<int, vector<int>> ump;
  vector<pi> py(m);
  rep (i, m) {
    int p, y; cin >> p >> y;
    py[i] = pi(p, y);
    ump[p].emplace_back(y);
  }
  for (auto& [_, v] : ump) sort(v.begin(), v.end());
  rep (i, m) {
    int p = py[i].first, y = py[i].second;
    auto it = lower_bound(ump[p].begin(), ump[p].end(), y);
    auto index = distance(ump[p].begin(), it);
    printf("%06d", p);
    printf("%06ld\n", index + 1);
  }
  return 0;
}