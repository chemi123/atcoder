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

// https://atcoder.jp/contests/abc223/tasks/abc223_d

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n);
  vector<int> degree(n); // 入次数
  rep (i, m) {
    int a, b; cin >> a >> b; --a, --b;
    graph[a].emplace_back(b);
    ++degree[b];
  }

  priority_queue<int, vector<int>, greater<int>> pq;
  rep (i, n) if (!degree[i]) pq.emplace(i);
  vector<int> ans;

  while (!pq.empty()) {
    int current = pq.top(); pq.pop();
    ans.emplace_back(current);
    for (auto next : graph[current]) {
      --degree[next];
      if (!degree[next]) pq.emplace(next);
    }
  }

  if (ans.size() != n) {
    cout << -1 << endl;
    return 0;
  }

  for (auto e : ans) cout << e + 1 << " "; cout << endl;

  return 0;
}