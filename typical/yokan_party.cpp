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

// https://atcoder.jp/contests/typical90/tasks/typical90_a

int main() {
  int n, l, k; cin >> n >> l >> k;
  vector<int> a(n);
  rep (i, n) cin >> a[i];

  auto check = [&](int x) -> bool {
    int cnt = 0, prev = 0;
    rep (i, n) {
      if (a[i] - prev >= x) {
        ++cnt;
        prev = a[i];
      }
    }
    if (l - prev >= x) ++cnt;
    return cnt >= k + 1;
  };

  int ok = 0, ng = l + 1;
  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
  return 0;
}