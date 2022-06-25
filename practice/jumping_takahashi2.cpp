#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
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

// https://atcoder.jp/contests/abc257/tasks/abc257_d

void dfs(const vector<pl>& xy, const vector<ll>& P, vector<bool>& visit, ll s, int current) {
  if (visit[current]) return;
  visit[current] = true;
  int n = (int)xy.size();

  auto [x1, y1] = xy[current];
  rep (next, n) {
    auto [x2, y2] = xy[next];
    ll ps = P[current] * s;
    if (ps >= (ll)abs(x1 - x2) + (ll)abs(y1 - y2)) dfs(xy, P, visit, s, next);
  }
}

int main() {
  int n; cin >> n;
  vector<pl> xy(n);
  vector<ll> P(n);
  rep (i, n) {
    ll x, y, p; cin >> x >> y >> p;
    xy[i] = pl(x, y);
    P[i] = p;
  }

  ll ok = 1e10, ng = 0;
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    bool ok2 = false;
    rep (i, n) {
      vector<bool> visit(n);
      dfs(xy, P, visit, mid, i);
      bool ok3 = true;
      for (auto e : visit) if (!e) ok3 = false;
      if (ok3) {
        ok2 = true;
        break;
      }
    }

    if (ok2) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}