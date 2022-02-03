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

// dp[i]: 石の残りがi個の時、Firstが勝てるかどうか。dp[0] = falseは自明
// 1 <= i <= kのそれぞれで、 0 <= j < nを全て探索し、dp[i - a[j]]を確認(ただし、i - a[j] >= 0)。もしdp[i - a[j]]にひとつでもfalseがあればそれをSecondに押し付ければ良いからtrueになる。
// https://atcoder.jp/contests/dp/tasks/dp_k

int main() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  rep (i, n) cin >> a[i];
  vector<bool> dp(k + 1);

  reps (i, 1, k + 1) rep (j, n) if (i - a[j] >= 0 && !dp[i - a[j]]) dp[i] = true;
  if (dp[k]) cout << "First" << endl;
  else cout << "Second" << endl;
  return 0;
}