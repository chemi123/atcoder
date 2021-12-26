#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
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

const int INF = 1e9;
const ll INFL = 1e15;
const ll MOD = 1000000007;

// https://atcoder.jp/contests/abc007/tasks/abc007_3

int main() {
  int r, c;
  cin >> r >> c;
  int sr, sc, gr, gc;
  cin >> sr >> sc >> gr >> gc;
  --sr, --sc, --gr, --gc;
  vector<string> graph(r);
  rep (i, r) cin >> graph[i];
  vector<pi> drdc{pi(1, 0), pi(-1, 0), pi(0, 1), pi(0, -1)};
  vector<vector<int>> dist(r, vector<int>(c, -1));
  dist[sr][sc] = 0;
  queue<pi> que;
  que.emplace(pi(sr, sc));
  while (!que.empty()) {
    auto [row, col] = que.front();
    que.pop();
    for (auto [dr, dc] : drdc) {
      int nextRow = row + dr, nextCol = col + dc;
      if (nextRow < 0 || nextRow >= r || nextCol < 0 || nextCol >= c) continue;
      if (graph[nextRow][nextCol] == '#') continue;
      if (dist[nextRow][nextCol] != -1) continue;
      dist[nextRow][nextCol] = dist[row][col] + 1;
      que.emplace(pi(nextRow, nextCol));
    }
  }
  cout << dist[gr][gc] << endl;
  return 0;
}
