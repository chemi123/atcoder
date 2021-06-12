#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <set>
#include <sstream>
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

// https://atcoder.jp/contests/abc183/tasks/abc183_c

int main() {
  int n, k; cin >> n >> k;
  vector<vector<int>> graph(n, vector<int>(n));
  rep (i, n) rep(j, n) cin >> graph[i][j];
  vector<int> node(n - 1);
  rep (i, n - 1) node[i] = i + 1;

  int ans = 0;
  do {
    int sum = 0;
    int cur = 0;
    for (auto next : node) {
      sum += graph[cur][next];
      cur = next;
    }
    sum += graph[cur][0];
    if (sum == k) ++ans;
  } while (next_permutation(node.begin(), node.end()));
  cout << ans << endl;
  return 0;
}
