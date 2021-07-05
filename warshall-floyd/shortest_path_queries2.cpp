#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
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

// https://atcoder.jp/contests/abc208/tasks/abc208_d

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n, vector<int>(n, INF));
  rep (i, m) {
    int a, b, c; cin >> a >> b >> c; --a, --b;
    graph[a][b] = c;
  }
  rep (i, n) graph[i][i] = 0;

  ll ans = 0;
  rep (via, n) {
    rep (from, n) rep (to, n) graph[from][to] = min(graph[from][to], graph[from][via] + graph[via][to]);
    rep (from, n) rep (to, n) if (graph[from][to] < INF) ans += graph[from][to];
  }
  cout << ans << endl;
  return 0;
}
