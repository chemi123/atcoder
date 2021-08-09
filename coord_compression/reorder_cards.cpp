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

// https://atcoder.jp/contests/abc213/tasks/abc213_c

int main() {
  int h, w, n; cin >> h >> w >> n;
  vector<int> a(n), b(n);
  rep (i, n) cin >> a[i] >> b[i];
  vector<int> tmpA, tmpB;
  tmpA = a, tmpB = b;

  sort(tmpA.begin(), tmpA.end());
  tmpA.erase(unique(tmpA.begin(), tmpA.end()), tmpA.end());
  sort(tmpB.begin(), tmpB.end());
  tmpB.erase(unique(tmpB.begin(), tmpB.end()), tmpB.end());

  rep (i, n) cout << lower_bound(tmpA.begin(), tmpA.end(), a[i]) - tmpA.begin() + 1 << " "
    << lower_bound(tmpB.begin(), tmpB.end(), b[i]) - tmpB.begin() + 1 << endl;
  return 0;
}