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

// https://atcoder.jp/contests/abc141/tasks/abc141_c

int main() {
  int n, k, q; cin >> n >> k >> q;
  vector<int> A(n);
  rep (i, q) {
    int a; cin >> a; --a;
    ++A[a];
  }
  for (auto a : A) {
    if (k - q + a > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
