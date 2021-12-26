#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

// https://atcoder.jp/contests/abc138/tasks/abc138_d

void dfs(const vector<vector<int>>& vertices, vector<int>& points, int v, int p) {
  if (p != -1) points[v] += points[p];
  for (auto vertice : vertices[v]) {
    if (vertice == p) continue;
    dfs(vertices, points, vertice, v);
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> vertices(n+1);
  rep (i, n-1) {
    int v1, v2;
    cin >> v1 >> v2;
    vertices[v1].emplace_back(v2);
    vertices[v2].emplace_back(v1);
  }
  vector<int> points(n+1, 0);
  rep (i, q) {
    int v, p;
    cin >> v >> p;
    points[v] += p;
  }
  dfs(vertices, points, 1, -1);
  for (int i = 1; i <= n; ++i) cout << points[i] << " "; cout << endl;
  return 0;
}
