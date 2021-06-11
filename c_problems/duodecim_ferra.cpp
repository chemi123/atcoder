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

// https://atcoder.jp/contests/abc185/tasks/abc185_c

int main() {
  ll l; cin >> l;
  vector<vector<ll>> combi(201, vector<ll>(201));
  combi[0][0] = 1;
  rep (i, 200) {
    rep (j, i + 1) {
      combi[i+1][j] += combi[i][j];
      combi[i + 1][j + 1] += combi[i][j];
    }
  }
  cout << combi[l-1][11] << endl;
  return 0;
}
