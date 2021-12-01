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

// https://atcoder.jp/contests/typical90/tasks/typical90_ag

int main() {
  int h, w; cin >> h >> w;
  if (h == 1 || w == 1) {
    cout << h * w << endl;
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < h; i += 2) for (int j = 0; j < w; j += 2) ++ans;
  cout << ans << endl;
  return 0;
}