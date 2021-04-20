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

const int INF = 1e9;
const ll INFL = 1e15;
const ll MOD = 1000000007;

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja

int main() {
  int v, e, r;
  cin >> v >> e >> r;
  vector<vector<pair<int, int>>> graph(v);
  rep (i, e) {
    int s, t, d;
    cin >> s >> t >> d;
    graph[s].emplace_back(make_pair(d, t));
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.emplace(make_pair(0, r));
  vector<int> dijk(v, INF);
  while (!pq.empty()) {
    auto [d, t] = pq.top();
    pq.pop();
    if (dijk[t] <= d) continue;
    dijk[t] = d;
    for (auto [dist, next] : graph[t]) pq.emplace(make_pair(dist + dijk[t], next));
  }
  for (auto e : dijk) {
    if (e == INF) cout << "INF" << endl;
    else cout << e << endl;
  }
  return 0;
}