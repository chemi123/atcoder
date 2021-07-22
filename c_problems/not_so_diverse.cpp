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

// https://atcoder.jp/contests/abc081/tasks/arc086_a

int main() {
  int n, k; cin >> n >> k;
  vector<int> v(n + 1);
  rep (i, n) {
    int a; cin >> a;
    ++v[a];
  }
  sort(v.begin(), v.end(), greater());
  while (!v.back()) v.pop_back();

  int ans = 0;
  while (v.size() > k) {
    ans += v.back();
    v.pop_back();
  }
  cout << ans << endl;
  return 0;
}