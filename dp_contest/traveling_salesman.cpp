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

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A&lang=ja

int main() {
  int v, e; cin >> v >> e;
  vector graph(v, vector<int>(v, -1));
  rep (i, e) {
    int s, t, d; cin >> s >> t >> d;
    graph[s][t] = d;
  }
  vector dp(1 << v, vector<int>(v, INF));
  dp[0][0] = 0;
  rep (S, 1 << v) {
    rep (from, v) rep (to, v) {
      if ((S >> to & 1) == 0 && graph[from][to] != -1) {
        int nextS = S | 1 << to;
        dp[nextS][to] = min(dp[nextS][to], dp[S][from] + graph[from][to]);
      }
    }
  }
  int allBits = (1 << v) - 1;
  if (dp[allBits][0] == INF) cout << -1 << endl;
  else cout << dp[allBits][0] << endl;
  return 0;
}