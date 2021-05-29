#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

// 汚い
// https://atcoder.jp/contests/abc111/tasks/arc103_a

int main() {
  int n; cin >> n;
  unordered_map<int, int> odd, even;
  rep (i, n) {
    int v; cin >> v;
    if (i % 2 == 0) ++even[v];
    else ++odd[v];
  }
  int m1 = 0, key1 = 0;
  for (auto [k, v] : odd) {
    if (v > m1) {
      m1 = v;
      key1 = k;
    }
  }
  int m2 = 0, key2 = 0;
  for (auto [k, v] : even) {
    if (v > m2) {
      m2 = v;
      key2 = k;
    }
  }
  if (key1 != key2) {
    cout << n - m1 - m2 << endl;
    return 0;
  }
  if (m1 > m2) {
    even.erase(key2);
    m2 = 0;
    for (auto [_, v] : even) m2 = max(m2, v);
    cout << n - m1 - m2 << endl;
    return 0;
  } else if (m2 > m1) {
    odd.erase(key1);
    m1 = 0;
    for (auto [_, v] : odd) m1 = max(m1, v);
    cout << n - m1 - m2 << endl;
    return 0;
  }
  int ans = n - m1;
  odd.erase(key1), even.erase(key2);
  m1 = 0, m2 = 0;
  for (auto [_, v] : odd) m1 = max(m1, v);
  for (auto [_, v] : even) m2 = max(m2, v);
  if (m1 >= m2) ans -= m1;
  else ans -= m2;
  cout << ans << endl;
  return 0;
}