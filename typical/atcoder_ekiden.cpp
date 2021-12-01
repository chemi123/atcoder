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

// https://atcoder.jp/contests/typical90/tasks/typical90_af

int main() {
  int n; cin >> n;
  vector<pair<int, vector<int>>> A;
  A.reserve(n);
  rep (i, n) {
    pair<int, vector<int>> p;
    p.first = i;
    rep (j, n) {
      int a; cin >> a;
      p.second.emplace_back(a);
    }
    A.emplace_back(p);
  }

  int m; cin >> m;
  map<int, vector<int>> ng;
  rep (i, m) {
    int x, y; cin >> x >> y; --x, --y;
    ng[x].emplace_back(y);
    ng[y].emplace_back(x);
  }

  int ans = INF;
  do {
    int sum = 0;
    rep (i, n) {
      auto [_, v] = A[i];
      sum += v[i];
    }

    bool ok = true;
    rep (i, n - 1) {
      auto [index, _] = A[i];
      if (find(ng[index].begin(), ng[index].end(), A[i+1].first) != ng[index].end()) ok = false;
    }

    if (ok) ans = min(ans, sum);
  } while (next_permutation(A.begin(), A.end()));
  if (ans == INF) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}