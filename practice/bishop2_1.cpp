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

// BFS
// https://atcoder.jp/contests/abc246/tasks/abc246_e

int main() {
  int n; cin >> n;
  int ax, ay, bx, by; cin >> ax >> ay >> bx >> by; --ax, --ay, --bx, --by;
  vector<string> s(n);
  rep (i, n) cin >> s[i];
  vector dist(n, vector<int>(n, INF));
  queue<pi> que;
  que.emplace(pi(ax, ay));
  dist[ax][ay] = 0;
  vector<pi> dxdy{pi(-1, -1), pi(1, 1), pi(1, -1), pi(-1, 1)};
  while (!que.empty()) {
    auto [curX, curY] = que.front(); que.pop();
    for (auto [dx, dy] : dxdy) {
      int nextX = curX + dx, nextY = curY + dy;
      while (nextX >= 0 && nextY >= 0 && nextX < n && nextY < n && s[nextX][nextY] == '.') {
        if (dist[nextX][nextY] < dist[curX][curY] + 1) break;
        dist[nextX][nextY] = dist[curX][curY] + 1;
        que.emplace(pi(nextX, nextY));
        nextX += dx;
        nextY += dy;
      }
    }
  }
  if (dist[bx][by] == INF) cout << -1 << endl;
  else cout << dist[bx][by] << endl;
  return 0;
}