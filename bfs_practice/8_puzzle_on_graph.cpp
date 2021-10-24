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

// https://atcoder.jp/contests/abc224/tasks/abc224_d

int main() {
  int m; cin >> m;
  vector<vector<int>> graph(9);
  rep (i, m) {
    int u, v; cin >> u >> v; --u, --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  string base = "ooooooooo";
  rep (i, 8) {
    int p; cin >> p; --p;
    base[p] = i + '0';
  }
  unordered_map<string, int> mp;
  mp[base] = 0;
  queue<string> que;
  que.emplace(base);
  while (!que.empty()) {
    string cur = que.front(); que.pop();
    auto curPos = cur.find("o");
    for (auto nextPos : graph[curPos]) {
      string next = cur;
      next[curPos] = cur[nextPos];
      next[nextPos] = 'o';
      if (mp.count(next)) continue;
      mp[next] = mp[cur] + 1;
      que.emplace(next);
    }
  }

  auto it = mp.find("01234567o");
  if (it == mp.end()) cout << -1 << endl;
  else cout << it->second << endl;
  return 0;
}