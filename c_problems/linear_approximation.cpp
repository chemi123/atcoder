#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

// https://atcoder.jp/contests/abc102/tasks/arc100_a

int main() {
  int n; cin >> n;
  vector<int> ABS(n);
  rep (i, n) {
    int a; cin >> a;
    ABS[i] = a - (i + 1);
  }
  sort(ABS.begin(), ABS.end());
  int b = ABS[ABS.size()/2];

  ll ans = 0;
  for (auto e : ABS) ans += abs(e - b);
  cout << ans << endl;
  return 0;
}