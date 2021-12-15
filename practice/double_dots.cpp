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

// https://atcoder.jp/contests/abc168/tasks/abc168_d

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n);
  rep (i, m) {
    int a, b; cin >> a >> b; --a, --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  vector<int> ans(n, -1);
  vector<int> dist(n, -1);
  queue<int> que;
  que.emplace(0);
  dist[0] = 0;
  while(!que.empty()) {
    int current = que.front(); que.pop();
    for (auto next : graph[current]) {
      if (dist[next] != -1) continue;
      que.emplace(next);
      dist[next] = dist[current] + 1;
      ans[next] = current;
    }
  }
  cout << "Yes" << endl;
  reps (i, 1, n) cout << ans[i] + 1 << endl;
  return 0;
}