#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

// https://atcoder.jp/contests/abc096/tasks/abc096_c

void dfs(const vector<string>& graph, vector<vector<bool>>& visit, int r, int c) {
  if (r < 0 || r >= graph.size() || c < 0 || c >= graph[0].size() || graph[r][c] == '.') return;
  if (visit[r][c]) return;
  visit[r][c] = true;
  dfs(graph, visit, r - 1, c);
  dfs(graph, visit, r + 1, c);
  dfs(graph, visit, r, c - 1);
  dfs(graph, visit, r, c + 1);
}

int main() {
  int h, w; cin >> h >> w;
  vector<string> graph(h);
  rep (i, h) cin >> graph[i];
  vector<vector<bool>> visit(h, vector<bool>(w));
  vector<pi> drdc{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  rep (r, h) {
    rep (c, h) {
      if (graph[r][c] == '#' && !visit[r][c]) {
        bool ok = false;
        for (auto [dr, dc] : drdc) {
          int nextRow = r + dr, nextCol = c + dc;
          if (nextRow < 0 || nextRow >= h || nextCol < 0 || nextCol >= w) continue;
          if (graph[nextRow][nextCol] == '#') ok = true;
        }

        if (!ok) {
          cout << "No" << endl;
          return 0;
        }
        dfs(graph, visit, r, c);
      }
    }
  }

  cout << "Yes" << endl;
  return 0;
}