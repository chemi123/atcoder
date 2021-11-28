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

// https://atcoder.jp/contests/typical90/tasks/typical90_ac

int main() {
  int w, n; cin >> w >> n;
  vector<pi> lr(n);
  vector<int> tmp;
  tmp.reserve(n * 2);
  rep (i, n) {
    int l, r; cin >> l >> r; --l, --r;
    lr[i] = pi(l, r);
    tmp.emplace_back(l);
    tmp.emplace_back(r);
  }
  sort(tmp.begin(), tmp.end());
  tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
  vector<int> heights(tmp.size());
  rep (i, n) {
    auto [l, r] = lr[i];
    int cl = lower_bound(tmp.begin(), tmp.end(), l) - tmp.begin();
    int cr = lower_bound(tmp.begin(), tmp.end(), r) - tmp.begin();
    int h = 0;
    reps (i, cl, cr + 1) h = max(h, heights[i] + 1);
    reps (i, cl, cr + 1) heights[i] = h;
    cout << h << endl;
  }
  return 0;
}