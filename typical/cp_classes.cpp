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

// https://atcoder.jp/contests/typical90/tasks/typical90_g

int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep (i, n) cin >> a[i];
  sort(a.begin(), a.end());
  int q; cin >> q;
  rep (i, q) {
    int b; cin >> b;
    auto it = lower_bound(a.begin(), a.end(), b);
    if (it == a.begin()) cout << abs(b - *it) << endl;
    else if (it == a.end()) cout << abs(b - a.back()) << endl;
    else cout << min(abs(b - *it), abs(b - *(it - 1))) << endl;
  }
  return 0;
}