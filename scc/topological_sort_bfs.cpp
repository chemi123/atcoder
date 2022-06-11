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
// けんちょんさんの説明では出次数を使っているが、入次数を使えば逆グラフを使う必要はなかった
// https://qiita.com/drken/items/996d80bcae64649a6580
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=ja

int main() {
  int v, e; cin >> v >> e;
  vector<vector<int>> graph(v);
  
  // 頂点の入次数
  vector<int> degree(v);

  rep (i, e) {
    int s, t; cin >> s >> t;
    graph[s].emplace_back(t);
    ++degree[t];
  }

  queue<int> que;
  rep (i, v) if (!degree[i]) que.emplace(i);
  vector<int> ans;
  ans.reserve(v);

  while (!que.empty()) {
    // 入次数0の頂点
    int current = que.front(); que.pop();
    ans.emplace_back(current);
    for (auto next : graph[current]) {
      --degree[next];
      // 入次数0ならqueueに入れる
      if (!degree[next]) que.emplace(next);
    }
  }

  for (auto e : ans) cout << e << endl;

  return 0;
}