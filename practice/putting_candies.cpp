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

// https://atcoder.jp/contests/abc241/tasks/abc241_e

int main() {
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  rep (i, n) cin >> a[i];
  vector<int> cnt(n), cycle;
  ll ans = 0;
  for (; k; --k) {
    int nextIndex = ans % n;
    if (cnt[nextIndex] == 1) {
      ll tmp = ans;
      while (cnt[nextIndex] == 1) {
        cycle.emplace_back(nextIndex);
        ++cnt[nextIndex];
        tmp += a[nextIndex];
        nextIndex = tmp % n;
      }
      break;
    }
    ++cnt[nextIndex];
    ans += a[nextIndex];
  }
  if (k == 0) {
    cout << ans << endl;
    return 0;
  }
  ll sum = 0;
  for (auto e : cycle) sum += a[e];
  ans += sum * (k / (ll)cycle.size());
  k %= (ll)cycle.size();
  rep (i, k) ans += a[cycle[i]];
  cout << ans << endl;
  return 0; 
}