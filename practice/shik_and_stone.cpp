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

// https://atcoder.jp/contests/agc007/tasks/agc007_a

int main() {
  int h, w; cin >> h >> w;
  vector<string> grid(h);
  rep (i, h) cin >> grid[i];
  vector visit(h, vector<bool>(w));
  visit[0][0] = true;
  queue<pi> que;
  que.emplace(pi(0, 0));
  vector<pi> ngmv{pi(-1, 0), pi(0, -1)};
  vector<pi> okmv{pi(1, 0), pi(0, 1)};
  bool ok = true;
  while (!que.empty()) {
    auto [cr, cc] = que.front(); que.pop();
    for (auto [dr, dc] : ngmv) {
      int nr = cr + dr, nc = cc + dc;
      if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
      if (visit[nr][nc]) continue;
      if (grid[nr][nc] == '#') ok = false;
    }
    for (auto [dr, dc] : okmv) {
      int nr = cr + dr, nc = cc + dc;
      if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
      if (visit[nr][nc]) continue;
      if (grid[nr][nc] == '#') {
        visit[nr][nc] = true;
        que.emplace(pi(nr, nc));
      }
    }
    if (que.size() > 1) ok = false;
    if (!ok) break;
  }
  if (ok) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}