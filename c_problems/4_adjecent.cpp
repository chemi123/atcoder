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

// https://atcoder.jp/contests/abc069/tasks/arc080_a

int main() {
  int n; cin >> n;
  int one = 0, two = 0, four = 0;
  rep (i, n) {
    int a; cin >> a;
    if (a % 4 == 0) ++four;
    else if (a % 2 == 0) ++two;
    else ++one;
  }
  if (one == 0) {
    cout << "Yes" << endl;
    return 0;
  }

  if (two % 2 == 0) {
    if (one > four + 1) cout << "No" << endl;
    else cout << "Yes" << endl;
  } else {
    if (one > four) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
  return 0;
}