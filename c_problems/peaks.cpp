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

// https://atcoder.jp/contests/abc166/tasks/abc166_c

int main() {
  int n, m; cin >> n >> m;
  vector<int> h(n);
  rep (i, n) cin >> h[i];
  vector<vector<int>> graph(n);
  rep (i, m) {
    int a, b; cin >> a >> b; --a, --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  int ans = 0;
  rep (i, n) {
    bool ok = true;
    for (auto e : graph[i]) {
      if (h[e] >= h[i]) {
        ok = false;
        break;
      }
    }
    if (ok) ++ans;
  }
  cout << ans << endl;
  return 0;
}
