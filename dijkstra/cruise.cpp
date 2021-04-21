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

// https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_f

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<pi>> graph(n);
  rep (i, k) {
    int num;
    cin >> num;
    if (num == 1) {
      int c, d, e;
      cin >> c >> d >> e;
      --c, --d;
      graph[c].emplace_back(pi(e, d));
      graph[d].emplace_back(pi(e, c));
      continue;
    }
    int a, b;
    cin >> a >> b;
    --a, --b;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<int> dijk(n, INF);
    pq.emplace(pi(0, a));
    while (!pq.empty()) {
      auto [d, t] = pq.top();
      pq.pop();
      if (dijk[t] < d) continue;
      dijk[t] = d;
      if (t == b) break;
      for (auto [dist, next] : graph[t]) pq.emplace(pi(dist + dijk[t], next));
    }
    if (dijk[b] == INF) cout << -1 << endl;
    else cout << dijk[b] << endl;
  }
  return 0;
}
