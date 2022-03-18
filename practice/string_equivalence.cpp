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

// https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_d

void dfs(vector<string>& ans, int n) {
  if ((int)ans[0].size() == n) return;
  vector<string> tmp;
  for (const auto str : ans) {
    int m = 0;
    rep (i, (int)str.size()) m = max(m, (int)(str[i] - 'a'));
    ++m;
    rep (i, m + 1) tmp.emplace_back(str + string(1, i + 'a'));
  }
  swap(tmp, ans);
  dfs(ans, n);
}

int main() {
  int n; cin >> n;
  vector<string> ans{"a"};
  dfs(ans, n);
  for (auto& e : ans) cout << e << endl;
  return 0;
}