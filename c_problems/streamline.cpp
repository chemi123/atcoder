#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

// https://atcoder.jp/contests/abc117/tasks/abc117_c

int main() {
  int n, m; cin >> n >> m;
  vector<int> x(m);
  rep (i, m) cin >> x[i];
  sort(x.begin(), x.end());

  vector<int> width(m-1);
  rep (i, m - 1) width[i] = x[i+1] - x[i];
  sort(width.begin(), width.end(), greater());

  width.resize(n - 1);
  unordered_map<int, int> ump;
  for (auto e : width) ++ump[e];
  int ans = x.back() - x[0];
  rep (i, m - 1) {
    int w = x[i+1] - x[i];
    if (ump.find(w) != ump.end()) {
      ans -= w;
      --ump[w];
      if (ump[w] == 0) ump.erase(w);
    }
  }
  cout << ans << endl;
  return 0;
}