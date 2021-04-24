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

const int INF = 1e9;
const ll INFL = 1e15;
const ll MOD = 1000000007;

int main() {
  int v, e, r; cin >> v >> e >> r;
  vector<vector<pi>> graph(v);
  rep (i, e) {
    int s, t, d; cin >> s >> t >> d;
    graph[s].emplace_back(pi(d, t));
  }
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  vector<int> dijk(v, INF);
  pq.emplace(pi(0, r));
  while (!pq.empty()) {
    auto [cost, current] = pq.top(); pq.pop();
    if (dijk[current] <= cost) continue;
    dijk[current] = cost;
    for (auto [d, next] : graph[current]) {
      if (d + cost >= dijk[next]) continue;
      pq.emplace(pi(d + cost, next));
    }
  }
  for (auto e : dijk) {
    if (e == INF) cout << "INF" << endl;
    else cout << e << endl;
  }
  return 0;
}
