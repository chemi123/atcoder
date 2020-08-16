#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < n; ++i)

// https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_b

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n, 0); 
  rep(i, n) cin >> a[i];

  ll ans = 1e15;
  rep (bit, (1 << n)) {
    if (bitset<32>(bit).count() != k) continue;

    ll cost = 0;
    ll maxH = a[0] + 1;
    rep (i, n) {
      if (bit & (1 << i)) {
        // 一番目のビルはコストがかからないからスキップ
        if (i == 0) continue;
        if (a[i] < maxH) {
          cost += (maxH - a[i]);
          ++maxH;
        } else {
          maxH = a[i] + 1;
        }
      } else {
        maxH = max(maxH, a[i]);
      }
    }
    ans = min(ans, cost);
  }
  cout << ans << endl;
  return 0;
}