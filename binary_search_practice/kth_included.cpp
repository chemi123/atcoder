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

// https://atcoder.jp/contests/abc205/tasks/abc205_d

int main() {
  int n, q; cin >> n >> q;
  vector<ll> a(n); 
  rep (i, n) cin >> a[i];
  vector<ll> skipCnt(n);
  rep (i, n) skipCnt[i] = a[i] - i - 1;

  rep (i, q) {
    ll k; cin >> k;
    int r = lower_bound(skipCnt.begin(), skipCnt.end(), k) - skipCnt.begin();
    ll ans = 0;
    if (r == 0) ans = k;
    else ans = a[r-1] + (k - skipCnt[r-1]);
    cout << ans << endl;
  }
}