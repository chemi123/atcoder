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

// https://atcoder.jp/contests/abc012/tasks/abc012_4

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n, vector<int>(n, INF));
  rep (i, m) {
    int a, b, t; cin >> a >> b >> t; --a, --b;
    graph[a][b] = t, graph[b][a] = t;
  }
  rep (i, n) graph[i][i] = 0;
  rep (via, n) {
    rep (from, n) {
      if (graph[from][via] == INF) continue;
      rep (to, n) {
        graph[from][to] = min(graph[from][to], graph[from][via] + graph[via][to]);
      }
    }
  }
  int ans = INF;
  for (auto& vec : graph) {
    int candidate = 0;
    for (auto e : vec) candidate = max(candidate, e);
    ans = min(ans, candidate);
  }
  cout << ans << endl;
  return 0;
}
