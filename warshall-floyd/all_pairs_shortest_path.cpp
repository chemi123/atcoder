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

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja

int main() {
  int v, e; cin >> v >> e;
  vector<vector<ll>> graph(v, vector<ll>(v, INFL));
  rep (i, e) {
    int s, t; cin >> s >> t;
    cin >> graph[s][t];
  }
  rep (i, v) graph[i][i] = 0;
  rep (via, v) {
    rep (from, v) {
      if (graph[from][via] == INFL) continue;
      rep (to, v) {
        if (graph[via][to] == INFL) continue;
        graph[from][to] = min(graph[from][to], graph[from][via] + graph[via][to]);
        if (from == to && graph[from][to] < 0) {
          cout << "NEGATIVE CYCLE" << endl;
          return 0;
        }
      }
    }
  }
  rep (i, v) {
    rep (j, v) {
      if (graph[i][j] == INFL) cout << "INF";
      else cout << graph[i][j];
      if (j == v - 1) cout << endl;
      else cout << " ";
    }
  }
  return 0;
}
