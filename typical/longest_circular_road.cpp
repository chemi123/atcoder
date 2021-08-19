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

// https://atcoder.jp/contests/typical90/tasks/typical90_c

void dfs(const vector<vector<int>>& graph, int &dest, int parent, int current, int l, int& maxL) {
  if (l > maxL) {
    maxL = l;
    dest = current;
  }

  for (auto next : graph[current]) {
    if (next == parent) continue;
    dfs(graph, dest, current, next, l + 1, maxL);
  }
}

int main() {
  int n; cin >> n;
  vector<vector<int>> graph(n);
  rep (i, n - 1) {
    int a, b; cin >> a >> b; --a, --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  int firstDest = 0, secondDest = 0, maxL = 0;
  dfs(graph, firstDest, -1, 0, 0, maxL);
  maxL = 0;
  dfs(graph, secondDest, -1, firstDest, 0, maxL);
  cout << maxL + 1 << endl;
  return 0;
}