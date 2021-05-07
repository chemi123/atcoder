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
using pl = pair<ll, ll>;

const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1000000007;

// https://atcoder.jp/contests/abc074/tasks/arc083_b

int main() {
  int n; cin >> n;
  vector<vector<ll>> graph(n, vector<ll>(n, 0));
  vector<vector<bool>> necessary(n, vector<bool>(n, true));
  rep (i, n) rep (j, n) cin >> graph[i][j];
  rep (via, n) {
    rep (from, n) {
      rep (to, n) {
        if (graph[from][to] > graph[from][via] + graph[via][to]) {
          cout << -1 << endl;
          return 0;
        } else if (graph[from][to] == graph[from][via] + graph[via][to] && from != via && to != via) {
          necessary[from][to] = false;
        }
      }
    }
  }
  ll ans = 0;
  rep (i, n) {
    rep (j, n) {
      if (necessary[i][j]) ans += graph[i][j];
    }
  }
  cout << ans / 2 << endl;
  return 0;
}
