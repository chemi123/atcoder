#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
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

// https://atcoder.jp/contests/abc203/tasks/abc203_d

int main() {
  int n, k; cin >> n >> k;
  vector<vector<int>> pond(n, vector<int>(n));
  rep (i, n) rep (j, n) cin >> pond[i][j];
  int ng = -1, ok = 1e9 + 1, median = (int)floor(k * k / 2) + 1;

  while (ok - ng > 1) {
    int mid = (ng + ok) / 2;

    // 二次元累積和の作成
    vector<vector<int>> acc(n + 1, vector<int>(n + 1));
    rep (row, n) rep (col, n) if (pond[row][col] > mid) acc[row+1][col+1] = 1;
    rep (row, n) rep (col, n) acc[row+1][col+1] += acc[row+1][col];
    rep (col, n) rep (row, n) acc[row+1][col+1] += acc[row][col+1];

    bool ok2 = false;
    reps (row, k, n + 1) reps (col, k, n + 1) {
      int accumulation = acc[row][col] - acc[row-k][col] - acc[row][col-k] + acc[row-k][col-k];
      if (accumulation < median) ok2 = true;
    }
    if (ok2) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;

  return 0;
}
