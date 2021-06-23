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

// https://atcoder.jp/contests/abc149/tasks/abc149_c

int main() {
  int x; cin >> x;
  reps (n, x, INF) {
    bool ok = true;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << n << endl;
      break;
    }
  }
  return 0;
}
