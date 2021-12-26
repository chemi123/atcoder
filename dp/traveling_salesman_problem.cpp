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
#define reps(i, s, n) for (int i = (s); i < (n); i++)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A&lang=ja
// 参考(ここが一番わかりやすかった): https://k0m-lime.hatenablog.com/entry/2021/02/07/183935

int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<int>> cost(V, vector<int>(V, -1));
  rep (i, E) {
    int from, to, distance;
    cin >> from >> to >> distance;
    cost[from][to] = distance;
  }
  // dp[S][from]: 集合Sを訪問し、現在fromにいる場合の最小コスト(from ∈ S、Sのビットにfromの指す位置のビットが立っている)
  vector<vector<int>> dp(1 << V, vector<int>(V, 1e9));
  // どこも探索しておらず、現在頂点0にいる状態
  dp[0][0] = 0;
  // 頂点をビットとみなして、Sをビットの集合として表現する
  rep (S, (1 << V)) {
    rep (from, V) {
      rep (to, V) {
        // Sは次の目的地のビットが含まれていないかつfromからtoの経路が存在することが更新の条件
        if ((S >> to & 1) == 0 && cost[from][to] != -1) {
          dp[S | 1 << to][to]  = min(dp[S | 1 << to][to], dp[S][from] + cost[from][to]);
        }
      }
    }
  }
  cout << ((dp[(1 << V) - 1][0] == 1e9) ? -1 : dp[(1 << V) - 1][0]) << endl;
  return 0;
}
