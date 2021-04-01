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
const int MOD = 10007;
const ll MODL = 1000000007;

// https://atcoder.jp/contests/joi2014yo/tasks/joi2014yo_d

int main() {
  auto add = [&](int &a, int b) {
    a += b;
    a %= MOD;
  };
  int n;
  cin >> n;
  string schedule;
  cin >> schedule;
  vector<vector<int>> dp(n + 1, vector<int>(1 << 3, 0));
  dp[0][1] = 1;
  rep (i, n) {
    int responsibility = 0;
    if (schedule[i] == 'O') responsibility = 1;
    if (schedule[i] == 'I') responsibility = 2;
    rep (S1, 1 << 3) {
      rep (S2, 1 << 3) {
        if ((S1 & S2) == 0) continue;
        if ((S2 >> responsibility & 1) == 0) continue;
        add(dp[i+1][S2], dp[i][S1]);
      }
    }
  }
  int res = 0;
  rep (i, 1 << 3) add(res, dp[n][i]);
  cout << res << endl;
  return 0;
}
