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

// ライブラリではないが、周期性を見つけて解を求める問題のプログラムの書き方サンプル
// https://atcoder.jp/contests/abc179/tasks/abc179_e

int main() {
  ll n, x, m; cin >> n >> x >> m;
  vector<int> cnt(m), cycle;
  ll ans = 0;
  for (; n; --n) {
    if (cnt[x]) {
      while (cnt[x] == 1) {
        cycle.emplace_back(x);
        ++cnt[x];
        x = x * x % m;
      }
      break;
    }
    ++cnt[x];
    ans += x;
    x = x * x % m;
  }
  if (n == 0) {
    cout << ans << endl;
    return 0;
  }
  ll sum = 0;
  for (auto e : cycle) sum += e;
  ans += sum * (n / cycle.size());
  n %= cycle.size();
  rep (i, n) ans += cycle[i];
  cout << ans << endl;
  return 0;
}