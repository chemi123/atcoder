#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

// https://atcoder.jp/contests/abc209/tasks/abc209_d

int main() {
  int n, q; cin >> n >> q;
  vector<vector<int>> graph(n);
  rep (i, n - 1) {
    int a, b; cin >> a >> b; --a, --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }

  vector<int> dist(n, -1);
  dist[0] = 0;
  queue<int> que;
  que.emplace(0);
  while (!que.empty()) {
    int current = que.front(); que.pop();
    for (auto next : graph[current]) {
      if (dist[next] != -1) continue;
      dist[next] = dist[current] + 1;
      que.emplace(next);
    }
  }

  rep (i, q) {
    int c, d; cin >> c >> d; --c, --d;
    if ((dist[c] + dist[d]) % 2 == 0) cout << "Town" << endl;
    else cout << "Road" << endl;
  }
  return 0;
}