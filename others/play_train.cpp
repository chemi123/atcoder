#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
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

// https://atcoder.jp/contests/abc225/tasks/abc225_d

int main() {
  int n, q; cin >> n >> q;
  vector<int> front(n + 1, -1);
  vector<int> back(n + 1, -1);
  rep (i, q) {
    int c; cin >> c;
    if (c == 1) {
      int x, y; cin >> x >> y;
      back[x] = y;
      front[y] = x;
      continue;
    } else if (c == 2) {
      int x, y; cin >> x >> y;
      back[x] = -1;
      front[y] = -1;
      continue;
    }
    int x; cin >> x;
    while (front[x] != -1) x = front[x];
    vector<int> ans{x};
    while (back[x] != -1) {
      x = back[x];
      if (x != -1) ans.emplace_back(x);
    }
    cout << ans.size() << " ";
    for (auto e : ans) cout << e << " "; cout << endl;
  }
  return 0;
}