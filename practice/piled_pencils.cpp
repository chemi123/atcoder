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

// https://atcoder.jp/contests/dwango2016-prelims/tasks/dwango2016qual_b

int main() {
  int n; cin >> n;
  vector<int> k(n-1);
  rep (i, n - 1) cin >> k[i];
  vector<int> ans(n);
  ans[0] = k[0];
  ans.back() = k.back();
  rep (i, n - 2) {
    if (k[i+1] >= k[i]) ans[i+1] = k[i];
    else ans[i+1] = k[i+1];
  }
  for (auto e : ans) cout << e << " "; cout << endl;
  return 0;
}