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
const ll INFL = 1e15;
const ll MOD = 1000000007;

// https://atcoder.jp/contests/joi2014yo/tasks/joi2014yo_e
// 改善の余地あり？

int main() {
  int n, k; cin >> n >> k;
  vector<pi> taxi(n);
  rep (i, n) {
    int fare, path; cin >> fare >> path;
    taxi[i] = pi(fare, path);
  }

  vector<vector<int>> graph(n);
  rep (i, k) {
    int a, b; cin >> a >> b; --a, --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }

  priority_queue<pi, vector<pi>, greater<pi>> pq;
  vector<int> dijk(n, INF);
  pq.emplace(pi(0, 0));
  while (!pq.empty()) {
    auto [cost, town] = pq.top(); pq.pop();
    if (dijk[town] <= cost) continue;
    dijk[town] = cost;

    queue<int> que;
    vector<int> dist(n, -1);
    que.emplace(town);
    dist[town] = 0;
    auto [fare, path] = taxi[town];
    int nextCost = fare + dijk[town];
    while (!que.empty()) {
      int cur = que.front(); que.pop();
      for (auto next : graph[cur]) {
        if (dist[next] != -1) continue;
        dist[next] = dist[cur] + 1;
        if (dist[next] > path) continue;
        que.emplace(next);
        if (nextCost < dijk[next]) pq.emplace(pi(nextCost, next));
      }
    }
  }

  cout << dijk[n-1] << endl;
  return 0;
}
