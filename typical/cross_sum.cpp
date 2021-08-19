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

// https://atcoder.jp/contests/typical90/tasks/typical90_d

int main() {
  int h, w; cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  rep (i, h) rep (j, w) cin >> a[i][j];
  vector<vector<int>> accRow(h, vector<int>(w));
  rep (i, h) rep (j, w) {
    if (j == 0) accRow[i][j] = a[i][j];
    else accRow[i][j] = accRow[i][j-1] + a[i][j];
  }

  vector<vector<int>> accCol(h, vector<int>(w));
  rep (i, w) rep (j, h) {
    if (j == 0) accCol[j][i] = a[j][i];
    else accCol[j][i] = accCol[j-1][i] + a[j][i];
  }
  rep (i, h) {
    rep (j, w) cout << accRow[i].back() + accCol.back()[j] - a[i][j] << " "; cout << endl;
  }
  return 0;
}