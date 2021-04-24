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
using pi = pair<ll, ll>;

const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1000000007;

// https://atcoder.jp/contests/joi2016yo/tasks/joi2016yo_e

int main() {
  // 順に町, 道, ゾンビ, 危険, 安宿, 高級宿
  ll n, m, k, s, p, q;
  cin >> n >> m >> k >> s >> p >> q;
  queue<ll> que;
  vector<ll> distToDanger(n, -1);
  rep (i, k) {
    int c; cin >> c; --c;
    que.emplace(c);
    distToDanger[c] = 0;
  }

  vector<vector<ll>> graph(n);
  rep (i, m) {
    int a, b; cin >> a >> b; --a, --b;
    graph[a].emplace_back(b); graph[b].emplace_back(a);
  }

  while (!que.empty()) {
    int cur = que.front();
    que.pop();
    for (auto next : graph[cur]) {
      if (distToDanger[next] != -1) continue;
      que.emplace(next);
      distToDanger[next] = distToDanger[cur] + 1;
    }
  }

  priority_queue<pi, vector<pi>, greater<pi>> pq;
  vector<ll> dijk(n, INFL);
  pq.emplace(pi(0, 0));
  while (!pq.empty()) {
    auto [cost, cur] = pq.top(); pq.pop();
    if (dijk[cur] <= cost) continue;
    dijk[cur] = cost;
    for (auto next : graph[cur]) {
      if (distToDanger[next] == 0) continue;
      ll nextCost = cost + (distToDanger[next] <= s ? q : p);
      // 枝刈り
      if (nextCost < dijk[next]) pq.emplace(pi(nextCost, next));
    }
  }
  cout << dijk[n-1] - (distToDanger[n-1] <= s ? q : p) << endl;

  return 0;
}