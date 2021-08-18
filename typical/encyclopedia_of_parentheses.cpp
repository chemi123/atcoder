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

// https://atcoder.jp/contests/typical90/tasks/typical90_b

void dfs(vector<string>& ans, string paren, int left, int right, int n) {
  if (right > left) return;
  if (left + right == n) {
    ans.emplace_back(paren);
    return;
  }

  if (left < n / 2) dfs(ans, paren + "(", left + 1, right, n);
  if (right < n / 2) dfs(ans, paren + ")", left, right + 1, n);
}

int main() {
  int n; cin >> n;
  if (n % 2 == 1) return 0;
  vector<string> ans;
  dfs(ans, "", 0, 0, n);
  for (auto e : ans) cout << e << endl;
  return 0;
}