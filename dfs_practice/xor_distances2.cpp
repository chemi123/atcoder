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
const ll MOD = 1e9 + 7;

// xor_distances.cppをdfs一回だけにして改良したバージョン

// xは頂点からxorしてきて、currentにいる時の値
void dfs(const vector<vector<pl>>& graph, vector<ll>& xorDist, ll x, ll current, ll parent) {
  for (const auto& [node, w] : graph[current]) {
    if (node == parent) continue;
    xorDist[node] = x ^ w;
    dfs(graph, xorDist, x ^ w, node, current);
  }
}

int main() {
  ll n; cin >> n;
  vector<vector<pl>> graph(n);
  rep (i, n - 1) {
    ll u, v, w; cin >> u >> v >> w; --u, --v;
    graph[u].emplace_back(pl(v, w));
    graph[v].emplace_back(pl(u, w));
  }
  // 頂点0からそれぞれの点までxorした距離
  vector<ll> xorDist(n);
  dfs(graph, xorDist, 0, 0, -1);
  ll ans = 0;
  rep (bit, 60) {
    ll cnt = 0;
    ll mask = 1LL << bit;
    rep (i, n) if ((xorDist[i] & mask) > 0) ++cnt;
    ans += (((n - cnt) * cnt % MOD) * (mask % MOD));
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
