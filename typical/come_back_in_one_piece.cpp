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

// https://atcoder.jp/contests/typical90/tasks/typical90_u

void dfs1(const vector<vector<int>>& graph, vector<int>& label, vector<bool>& visit, ll& cnt, int current) {
  if (visit[current]) return;
  visit[current] = true;
  for (auto next : graph[current]) dfs1(graph, label, visit, cnt, next);
  label[cnt] = current;
  ++cnt;
}

void dfs2(const vector<vector<int>>& graph, vector<bool>& visit, ll& cnt, int current) {
  if (visit[current]) return;
  visit[current] = true;
  ++cnt;
  for (auto next : graph[current]) dfs2(graph, visit, cnt, next);
}

int main() {
  int n, m; cin >> n >> m;
  vector graph1(n, vector<int>(0)), graph2(n, vector<int>(0));
  rep (i, m) {
    int a, b; cin >> a >> b; --a, --b;
    graph1[a].emplace_back(b);
    graph2[b].emplace_back(a);
  }
  vector<int> label(n);
  vector<bool> visit(n);
  ll cnt = 0;
  rep (i, n) dfs1(graph1, label, visit, cnt, i);
  rep (i, n) visit[i] = false;
  ll ans = 0;
  for (int i = n - 1; i >= 0; --i) if (!visit[label[i]]) {
    cnt = 0;
    dfs2(graph2, visit, cnt, label[i]);
    ans += (cnt * (cnt - 1) / 2);
  }
  cout << ans << endl;
  return 0;
}