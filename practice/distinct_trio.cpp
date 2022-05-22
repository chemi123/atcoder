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

// https://atcoder.jp/contests/abc252/tasks/abc252_d

int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep (i, n) cin >> a[i];
  map<int, int> m;
  rep (i, n) ++m[a[i]];
  vector<vector<int>> v;
  for (auto [num, cnt] : m) v.emplace_back(vector<int>(cnt, num));
  int sz = v.size();
  ll cnt = v[0].size();
  ll ans = 0;
  reps (i, 1, sz - 1) {
    ans += cnt * v[i].size() * (n - v[i].size() - cnt);
    cnt += v[i].size();
  }
  cout << ans << endl;
  return 0;
}