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

// https://atcoder.jp/contests/abc236/tasks/abc236_d

void dfs(const vector<vector<int>>& a, vector<bool>& used, int& ans, int eor, int n) {
  int l = 0;
  while (used[l] && l < 2 * n) ++l;
  if (l >= 2 * n) {
    ans = max(ans, eor);
    return;
  }
  used[l] = true;
  reps (r, l + 1, 2 * n) {
    if (used[r]) continue;
    used[r] = true;
    dfs(a, used, ans, eor ^ a[l][r], n);
    used[r] = false;
  }
  used[l] = false;
}

int main() {
  int n; cin >> n;
  vector a(2 * n, vector<int>(2 * n, -1));
  rep (i, 2 * n) {
    reps (j, i + 1, 2 * n) {
      int num; cin >> num;
      a[i][j] = num;
    }
  }

  int ans = 0;
  vector<bool> used(2 * n);
  dfs(a, used, ans, 0, n);
  cout << ans << endl;
  return 0;
}