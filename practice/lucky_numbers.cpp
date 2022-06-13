#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
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

/*
  難しかった。以下を参考にした。
  https://atcoder.jp/contests/abc255/editorial/4098

  A[0]をaとして置くと、1 <= i <= n-1までのA[i]が一意に求まる。
  そしてBを定義し(上のリンクを参考)、aをn, mで全探索。最も出現が多いaの出現数が答えになる。
*/ 

// https://atcoder.jp/contests/abc255/tasks/abc255_e

int main() {
  int n, m; cin >> n >> m;
  vector<ll> s(n - 1), x(m), b(n);
  rep (i, n - 1) cin >> s[i];
  rep (i, m) cin >> x[i];
  reps (i, 1, n) b[i] = s[i-1] - b[i-1];

  map<ll, ll> mp;
  rep (i, n) {
    ll c = (i % 2 == 0) ? 1 : -1;
    rep (j, m) {
      ll a = (x[j] - b[i]) * c;
      ++mp[a];
    }
  }

  ll ans = 0;
  for (auto [_, cnt] : mp) ans = max(ans, cnt);
  cout << ans << endl;

  return 0;
}