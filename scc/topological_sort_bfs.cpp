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

// bfsを使ったトポロジカルソート
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=ja

int main() {
  int v, e; cin >> v >> e;
  // 逆グラフ
  vector<vector<int>> rgraph(v);
  
  // 頂点の出次数
  vector<int> degree(v);

  rep (i, e) {
    int s, t; cin >> s >> t;
    rgraph[t].emplace_back(s);
    ++degree[s];
  }

  queue<int> que;
  rep (i, v) if (!degree[i]) que.emplace(i);
  vector<int> ans;
  ans.reserve(v);

  while (!que.empty()) {
    // sinkとは出次数0の頂点をを意味する
    int sink = que.front(); que.pop();
    ans.emplace_back(sink);
    for (auto next : rgraph[sink]) {
      --degree[next];
      if (!degree[next]) que.emplace(next);
    }
  }
  reverse(ans.begin(), ans.end());

  for (auto e : ans) cout << e << endl;

  return 0;
}