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
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1167&lang=jp

int main() {
  int maxRow = 180; // n(n+1)(n+2)/6が10^6を超えない最大の数
  auto f = [](int n) { return n * (n + 1) * (n + 2) / 6; };
  while (1) {
    int n;
    cin >> n;
    if (n == 0) break;
    vector<vector<int>> dp1(maxRow + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dp2(maxRow + 1, vector<int>(n + 1, 0));
    rep (i, n+1) {
      dp1[1][i] = i;
      dp2[1][i] = i;
    }
    int ansIndex = maxRow;
    for (int i = 1; i < maxRow; ++i) {
      if (f(i+1) > n) {
        ansIndex = i;
        break;
      }
      rep (j, n+1) {
        int num = f(i+1);
        if (num > j) {
          dp1[i+1][j] = dp1[i][j];
          dp2[i+1][j] = dp2[i][j];
        } else {
          dp1[i+1][j] = min({dp1[i][j], dp1[i][j-num] + 1, dp1[i+1][j-num] + 1});
          if (num % 2 == 0) dp2[i+1][j] = dp2[i][j];
          else dp2[i+1][j] = min({dp2[i][j], dp2[i][j-num] + 1, dp2[i+1][j-num] + 1});
        }
      }
    }
    cout << dp1[ansIndex][n] << " " << dp2[ansIndex][n] <<  endl;
  }
  return 0;
}
