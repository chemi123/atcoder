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

const int inf = 1e9;
const ll infl = 1e18;
const ll mod = 1000000007;

// https://atcoder.jp/contests/abc119/tasks/abc119_c

void dfs(const vector<int>& l, vector<int>& a, vector<int>& b, vector<int>& c, int A, int B, int C, int& ans, int index) {
  if (index == l.size()) {
    if (a.empty() || b.empty() || c.empty()) return;
    int cost = 0;
    cost += (a.size() - 1) * 10;
    cost += (b.size() - 1) * 10;
    cost += (c.size() - 1) * 10;
    int sumA = 0, sumB = 0, sumC = 0;
    for (auto e : a) sumA += e;
    for (auto e : b) sumB += e;
    for (auto e : c) sumC += e;
    cost += abs(sumA - A) + abs(sumB - B) + abs(sumC - C);
    ans = min(ans, cost);
    return;
  }

  rep (i, 4) {
    if (i == 0) {
      a.emplace_back(l[index]);
      dfs(l, a, b, c, A, B, C, ans, index + 1);
      a.pop_back();
    } else if (i == 1) {
      b.emplace_back(l[index]);
      dfs(l, a, b, c, A, B, C, ans, index + 1);
      b.pop_back();
    } else if (i == 2) {
      c.emplace_back(l[index]);
      dfs(l, a, b, c, A, B, C, ans, index + 1);
      c.pop_back();
    } else {
      dfs(l, a, b, c, A, B, C, ans, index + 1);
    }
  }
}

int main() {
  int n, A, B, C; cin >> n >> A >> B >> C;
  vector<int> l(n);
  rep (i, n) cin >> l[i];
  int ans = inf;

  vector<int> a, b, c;
  dfs(l, a, b, c, A, B, C, ans, 0);
  cout << ans << endl;
  return 0;
}