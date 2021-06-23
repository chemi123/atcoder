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

// https://atcoder.jp/contests/abc151/tasks/abc151_c

int main() {
  int n, m; cin >> n >> m;
  vector<bool> ac(n);
  vector<int> wa(n);
  rep (i, m) {
    int p; string str; cin >> p >> str; --p;
    if (str == "AC") ac[p] = true;
    if (str == "WA" && !ac[p]) ++wa[p];
  }
  int correct = 0, penalty = 0;
  rep (i, n) if (ac[i]) {
    ++correct;
    penalty += wa[i];
  }
  cout << correct << " " << penalty << endl;
  return 0;
}
