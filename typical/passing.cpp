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

// https://atcoder.jp/contests/typical90/tasks/typical90_m

void dijkstra(const vector<vector<pi>>& graph, vector<int>& dijk, int from) {
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  pq.emplace(pi(0, from));
  while (!pq.empty()) {
    auto [cost, current] = pq.top(); pq.pop();
    if (dijk[current] <= cost) continue;
    dijk[current] = cost;
    for (auto [weight, next] : graph[current]) {
      int nextWeight = weight + dijk[current];
      if (dijk[next] > nextWeight) pq.emplace(pi(nextWeight, next));
    }
  }
}

int main() {
  int n, m; cin >> n >> m;
  vector<vector<pi>> graph(n);
  rep (i, m) {
    int a, b, c; cin >> a >> b >> c; --a, --b;
    graph[a].emplace_back(pi(c, b));
    graph[b].emplace_back(pi(c, a));
  }
  vector<int> dijk1(n, INF);
  vector<int> dijk2(n, INF);
  dijkstra(graph, dijk1, 0);
  dijkstra(graph, dijk2, n - 1);

  rep (i, n) cout << dijk1[i] + dijk2[i] << endl;
  return 0;
}