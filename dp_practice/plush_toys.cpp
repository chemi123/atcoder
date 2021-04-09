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
#define reps(i, s, n) for (int i = s; i < n; i++)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

const int INF = 1e9;
const ll INFL = 1e15;
const ll MOD = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> toys(n, 0), cnt(m, 0);
  // acc[i][j]: i(0 <= i < m)番目のぬいぐるみがj(0 <= j < n)番目の位置にいる場合の累積
  vector<vector<int>> acc(m, vector<int>(n, 0));
  rep (i, n) {
    cin >> toys[i];
    --toys[i];
    ++cnt[toys[i]];
    acc[toys[i]][i] = 1;
  }
  rep (i, m) reps (j, 1, n) acc[i][j] += acc[i][j-1];
  vector<int> dp(1 << m, INF);
  dp[0] = 0;
  rep (S, 1 << m) {
    // 整列済人形の数
    int done = 0;
    rep (i, m) if (S >> i & 1) done += cnt[i];
    rep (i, m) {
      if (S >> i & 1) continue;
      // l以降にぬいぐるみiを置くためのコスト
      int cost = cnt[i] - acc[i][done + cnt[i] - 1];
      if (done > 0) cost += acc[i][done-1];
      dp[S | 1 << i] = min(dp[S | 1 << i], dp[S] + cost);
    }
  }
  cout << dp[(1 << m) - 1] << endl;

  return 0;
}