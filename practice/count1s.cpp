#include <algorithm>
#include <bitset>
#include <cassert>
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

// https://atcoder.jp/contests/arc137/tasks/arc137_b

int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep (i, n) cin >> a[i];
  vector<int> flip(n);
  rep (i, n) {
    if (a[i] == 1) flip[i] = -1;
    else flip[i] = 1;
  }
  vector<int> acc(n);
  acc[0] = flip[0];
  reps (i, 1, n) acc[i] = acc[i-1] + flip[i];
  int maxNum = 0, minNum = 0, maxDiff = 0, minDiff = 0;
  rep (i, n) {
    maxDiff = max(maxDiff, acc[i] - minNum);
    minDiff = min(minDiff, acc[i] - maxNum);
    maxNum = max(maxNum, acc[i]);
    minNum = min(minNum, acc[i]);
  }
  cout << maxDiff - minDiff + 1 << endl;
  return 0;
}