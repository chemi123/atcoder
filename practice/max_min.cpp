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

// https://atcoder.jp/contests/abc247/tasks/abc247_e

ll calc(const vector<int>& b, int x, int y) {
  int left = 0, right = 0, cntX = 0, cntY = 0;
  int n = (int)b.size();
  ll res = 0;
  while (left < n) {
    while (right < n && (cntX == 0 || cntY == 0)) {
      if (b[right] == x) ++cntX;
      if (b[right] == y) ++cntY;
      ++right;
    }
    if (cntX > 0 && cntY > 0) res += n + 1 - right;
    if (b[left] == x) --cntX;
    if (b[left] == y) --cntY;
    ++left;
  }
  return res;
}

int main() {
  int n, x, y; cin >> n >> x >> y;
  vector<int> a(n);
  rep (i, n) cin >> a[i];

  int index = 0;
  ll ans = 0;
  while (index < n) {
    vector<int> b;
    b.reserve(n);
    while (index < n && y <= a[index] && a[index] <= x) {
      b.emplace_back(a[index]);
      ++index;
    }
    if (b.size() >= 1) ans += calc(b, x, y);
    else ++index;
  }
  cout << ans << endl;
  return 0;
}