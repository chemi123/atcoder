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

// https://atcoder.jp/contests/abc011/tasks/abc011_3

int main() {
  int n; cin >> n;
  vector<int> ng(3);
  rep (i, 3) cin >> ng[i];
  if (find(ng.begin(), ng.end(), n) != ng.end()) {
    cout << "NO" << endl;
    return 0;
  }
  rep (i, 100) {
    if (n <= 3) {
      n = 0;
      break;
    }
    if (find(ng.begin(), ng.end(), n - 3) == ng.end()) {
      n -= 3;
      continue;
    }
    if (find(ng.begin(), ng.end(), n - 2) == ng.end()) {
      n -= 2;
      continue;
    }
    if (find(ng.begin(), ng.end(), n - 1) == ng.end()) --n;
  }
  if (n == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}