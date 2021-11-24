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

// https://atcoder.jp/contests/typical90/tasks/typical90_ab

int main() {
  int n; cin >> n;
  vector graph(1002, vector<int>(1002));
  rep (i, n) {
    int lx, ly, rx, ry; cin >> lx >> ly >> rx >> ry;
    ++graph[lx][ly];
    --graph[lx][ry];
    ++graph[rx][ry];
    --graph[rx][ly];
  }
  rep (y, 1001) reps (x, 1, 1002) graph[x][y] += graph[x-1][y];
  rep (x, 1001) reps (y, 1, 1002) graph[x][y] += graph[x][y-1];
  vector<int> ans(n + 1);
  rep (y, 1002) rep (x, 1002) ++ans[graph[x][y]];
  reps (i, 1, n + 1) cout << ans[i] << endl;
  return 0;
}