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

// 木の頂点からそれぞれの点までの重みをxorした際に、bit表現で1桁目が1の数をreturn
// xは頂点からxorしてきた時の現在の点の値(0 or 1になる、頂点は0として考える)
ll dfs(const vector<vector<pl>>& graph, ll x, ll current, ll parent) {
  ll res = x;
  for (const auto& [to, w] : graph[current]) {
    if (to == parent) continue;
    res += dfs(graph, (w & 1) ^ x, to, current);
  }
  return res;
}

/*
  方針: それぞれのbitの桁毎に考える。(xor問題の典型テク)
      　頂点からそれぞれの点までの重みをxorした際に、bit表現で1桁目が1の数と0の数を掛け算してそれに2^桁数を掛けた値が解となる。
*/

int main() {
  ll n; cin >> n;
  vector<vector<pl>> graph(n);
  rep (i, n - 1) {
    ll u, v, w; cin >> u >> v >> w; --u, --v;
    graph[u].emplace_back(pl(v, w));
    graph[v].emplace_back(pl(u, w));
  }
  ll ans = 0;
  ll bit = 1;
  rep (i, 60) {
    ll one = dfs(graph, 0L, 0L, -1L);
    ans += (((n - one) * one % MOD) * (bit % MOD));
    ans %= MOD;
    bit <<= 1;
    // 全ての辺の重みを1桁右シフト
    for (auto& nodes : graph) for (auto& [_, w] : nodes) w >>= 1;
  }
  cout << ans << endl;
  return 0;
}
