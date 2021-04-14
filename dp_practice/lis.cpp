#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

const int INF = 1e9;
const ll MOD = 1000000007;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=ja

int main() {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  rep (i, n) cin >> a[i];
  vector<int> dp(1, a[0]);
  dp.reserve(n);
  reps (i, 1, n) {
    if (dp.back() < a[i]) dp.emplace_back(a[i]);
    else *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
  }
  cout << dp.size() << endl;
  return 0;
}
