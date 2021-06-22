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

// https://atcoder.jp/contests/abc165/tasks/abc165_c

void dfs(vector<int>& A, const vector<int>& a, const vector<int>& b, const vector<int>& c, const vector<int>& d, int n, int m, int q, int num, int cnt, ll& ans) {
  if (cnt == n) {
    ll sum = 0;
    rep (i, q) if (A[b[i]] - A[a[i]] == c[i]) sum += d[i];
    if (sum > ans) ans = sum;
    return;
  }
  reps (i, num, m + 1) {
    A.emplace_back(i);
    dfs(A, a, b, c, d, n, m, q, i, cnt + 1, ans);
    A.pop_back();
  }
}

int main() {
  int n, m, q; cin >> n >> m >> q;
  vector<int> A, a(q), b(q), c(q), d(q);
  rep (i, q) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    --a[i], --b[i];
  }
  ll ans = 0;
  dfs(A, a, b, c, d, n, m, q, 1, 0, ans);
  cout << ans << endl;
  return 0;
}
