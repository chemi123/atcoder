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

// https://atcoder.jp/contests/abc098/tasks/arc098_a

int main() {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> accE(n), accW(n);
  if (s[0] == 'E') accE[0] = 1;
  else accW[0] = 1;
  reps (i, 1, n) {
    accE[i] = accE[i-1];
    accW[i] = accW[i-1];
    if (s[i] == 'E') ++accE[i];
    else ++accW[i];
  }

  int ans = INF;
  rep (i, n) {
    int tmp = 0;
    if (i > 0) tmp += accW[i-1];
    tmp += accE.back() - accE[i];
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}