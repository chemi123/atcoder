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

// https://atcoder.jp/contests/abc072/tasks/arc082_a

int main() {
  int n; cin >> n;
  unordered_map<int, int> m;
  rep (i, n) {
    int a; cin >> a;
    ++m[a], ++m[a-1], ++m[a+1];
  }
  int ans = 0;
  for (auto [_, cnt] : m) ans = max(ans, cnt);
  cout << ans << endl;
  return 0;
}