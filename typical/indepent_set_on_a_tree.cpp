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

// https://atcoder.jp/contests/typical90/tasks/typical90_z

void dfs(const vector<vector<int>>& graph, vector<bool>& node, int current, int parent, bool red) {
  node[current] = red;
  for (auto next : graph[current]) if (next != parent) dfs(graph, node, next, current, !red);
}

int main() {
  int n; cin >> n;
  vector<vector<int>> graph(n);
  rep (i, n - 1) {
    int a, b; cin >> a >> b; --a, --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  vector<bool> node(n);
  dfs(graph, node, 0, -1, true);
  int cnt = 0;
  rep (i, n) if (node[i]) ++cnt;
  bool ok = (cnt >= n / 2);
  cnt = 0;
  rep (i, n) {
    if (ok) if (node[i]) {
      cout << i + 1 << " ";
      ++cnt;
    }
    if (!ok) if (!node[i]) {
      cout << i + 1 << " ";
      ++cnt;
    }
    if (cnt >= n / 2) break;
  }
  cout << endl;
  return 0;
}