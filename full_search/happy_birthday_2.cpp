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
const ll MOD = 200;

// https://atcoder.jp/contests/abc200/tasks/abc200_d

int main() {
  int n; cin >> n;
  vector<int> a(n, 0);
  rep (i, n) {
    cin >> a[i];
    a[i] = a[i] % MOD;
  }
  int shift = (n >= 8) ? 8 : n;
  vector<int> pattern(1 << shift, 0);
  reps (S, 1, 1 << shift) {
    vector<int> bit;
    rep (i, shift) if (S >> i & 1) bit.emplace_back(i);
    int sum = 0;
    for (auto index : bit) sum += a[index];
    sum %= 200;
    pattern[S] = sum;
  }
  unordered_map<int, vector<int>> ump;
  reps (S, 1, 1 << shift) ump[pattern[S]].emplace_back(S);
  for (auto &[m, vec] : ump) {
    if (vec.size() < 2) continue;
    cout << "Yes" << endl;
    rep (i, 2) {
      vector<int> bit;
      rep (j, shift) if (vec[i] >> j & 1) bit.emplace_back(j + 1);
      cout << bit.size() << " ";
      for (auto e : bit) cout << e << " "; cout << endl;
    }
    return 0;
  }
  cout << "No" << endl;
  return 0;
}
