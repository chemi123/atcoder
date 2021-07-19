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

// https://atcoder.jp/contests/abc092/tasks/arc093_a

int main() {
  int n; cin >> n;
  vector<int> a(n); 
  rep (i, n) cin >> a[i];
  int sum = 0;
  rep (i, n) {
    if (i == 0) sum += abs(a[i]);
    else sum += abs(a[i] - a[i-1]);
  }
  sum += abs(a.back());

  rep (i, n) {
    if (i == 0) cout << sum - abs(a[i]) - abs(a[i+1] - a[i]) + abs(a[i+1]) << endl;
    else if (i < n - 1) cout << sum - abs(a[i] - a[i-1]) - abs(a[i+1] - a[i]) + abs(a[i+1] - a[i-1]) << endl;
    else cout << sum - abs(a[i] - a[i-1]) - abs(a.back()) + abs(a[i-1]) <<  endl;
  }
  return 0;
}