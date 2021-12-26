#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

// https://atcoder.jp/contests/abc150/tasks/abc150_c

int main() {
  int n;
  cin >> n;
  vector<int> p(n, 0), q(n, 0), v(n);
  rep (i, n) cin >> p[i];
  rep (i, n) cin >> q[i];
  rep (i, n) v[i] = i + 1;

  int a = 1, b = 1;
  bool pDone = false, qDone = false;
  do {
    bool allMatchP = true;
    bool allMatchQ = true;
    rep (i, n) {
      if (p[i] != v[i]) allMatchP = false;
      if (q[i] != v[i]) allMatchQ = false;
    }
    if (allMatchP) pDone = true;
    if (allMatchQ) qDone = true;
    if (pDone && qDone) break;
    if (!pDone) ++a;
    if (!qDone) ++b;
  } while (next_permutation(v.begin(), v.end()));
  cout << abs(a-b) << endl;
  return 0;
}