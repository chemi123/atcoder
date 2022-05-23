#include <algorithm>
#include <bitset>
#include <cassert>
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
using tp = tuple<ll, ll, ll>;

const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1000000007;

int main() {
  int n, m; cin >> n >> m;
  // (重み, 次の頂点, 辺のindex)を表すタプル
  vector<vector<tp>> graph(n);
  rep (i, m) {
    int a, b, c; cin >> a >> b >> c; --a, --b;
    graph[a].emplace_back(tp((ll)c, b, i + 1));
    graph[b].emplace_back(tp((ll)c, a, i + 1));
  }

  vector<ll> dijk(n, INFL);
  vector<int> indice(n);
  // (コスト, 次の頂点, index)
  priority_queue<tp, vector<tp>, greater<tp>> pq;
  pq.emplace(tp(0, 0, -1));
  while (!pq.empty()) {
    auto [cost, current, index] = pq.top(); pq.pop();
    if (cost >= dijk[current]) continue;
    dijk[current] = cost;
    indice[current] = index;
    for (auto [weight, next, idx] : graph[current]) {
      ll next_cost = weight + cost;
      if (next_cost < dijk[next]) pq.emplace(tp(next_cost, next, idx));
    }
  }
  reps (i, 1, n) cout << indice[i] << " "; cout << endl;
  return 0;
}