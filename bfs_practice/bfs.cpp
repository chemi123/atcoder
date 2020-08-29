#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja

int main() {
  int n;
  cin >> n;
  vector<vector<int>> vertices(n + 1, vector<int>(0));
  rep (i, n) {
    int vertice, sides;
    cin >> vertice >> sides;
    rep (j, sides) {
      int v;
      cin >> v;
      vertices[vertice].emplace_back(v);
    }
  }
  vector<int> ans(n + 1, -1);
  ans[1] = 0;
  queue<int> q;
  for (const auto e : vertices[1]) q.push(e);

  int step = 1;
  while (!q.empty()) {
    int size = (int)q.size();
    for (int i = 0; i < size; ++i) {
      int v = q.front();
      q.pop();
      if (ans[v] == -1) {
        ans[v] = step;
      } else {
        ans[v] = min(ans[v], step);
      }
      for (auto vertice : vertices[v]) {
        if (ans[vertice] == -1) q.push(vertice);
      }
    }
    ++step;
  }

  for (int i = 1; i <= n; ++i) cout << i << " " << ans[i] << endl;
  return 0;
}