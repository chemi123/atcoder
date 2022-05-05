#include <algorithm>
#include <bitset>
#include <cassert>
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

// https://atcoder.jp/contests/abc198/tasks/abc198_e

void dfs(const vector<vector<int>>& graph, const vector<int>& c, vector<int>& cnt, vector<bool>& isGood, int current, int parent) {
  if (cnt[c[current]] == 0) isGood[current] = true;
  ++cnt[c[current]];
  for (auto next : graph[current]) if(next != parent) dfs(graph, c, cnt, isGood, next, current);
  --cnt[c[current]];
}

int main() {
  int n; cin >> n;
  vector<int> c(n);
  rep (i, n) {
    cin >> c[i];
    --c[i];
  }
  vector<vector<int>> graph(n);
  rep (i, n - 1) {
    int a, b; cin >> a >> b; --a, --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  vector<int> cnt(1e5 + 10);
  vector<bool> isGood(n);
  dfs(graph, c, cnt, isGood, 0, -1);
  rep (i, n) if (isGood[i]) cout << i + 1 << endl;
  return 0;
}