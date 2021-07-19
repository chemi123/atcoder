#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

// https://atcoder.jp/contests/abc088/tasks/abc088_c

int main() {
  vector<vector<int>> c(3, vector<int>(3));
  rep (i, 3) rep (j, 3) cin >> c[i][j];

  rep (a1, 101) rep (a2, 101) rep(a3, 101) {
    int b1 = c[0][0] - a1;
    int b2 = c[0][1] - a1;
    int b3 = c[0][2] - a1;

    vector<int> A{a1, a2, a3};
    vector<int> B{b1, b2, b3};

    bool ok = true;
    rep (i, 3) rep (j, 3) if (A[i] + B[j] != c[i][j]) ok = false;
    if (ok) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}