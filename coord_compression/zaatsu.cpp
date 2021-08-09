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

// https://atcoder.jp/contests/abc036/tasks/abc036_c

int main() {
  int n; cin >> n;
  vector<int> a(n), tmp;
  rep (i, n) cin >> a[i];
  tmp = a;
  sort(tmp.begin(), tmp.end());
  auto it = unique(tmp.begin(), tmp.end());
  tmp.erase(it, tmp.end());
  for (auto e : a) cout << lower_bound(tmp.begin(), tmp.end(), e) - tmp.begin() << endl;
  return 0;
}