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

// https://atcoder.jp/contests/abc173/tasks/abc173_c

int main() {
  int h, w, k; cin >> h >> w >> k;
  vector<string> graph(h);
  rep (i, h) cin >> graph[i];
  int ans = 0;
  rep (i, (1 << h)) {
    vector<int> hBits(h);
    rep (bit, h) {
      if (i >> bit & 1) hBits[bit] = 1;
      else hBits[bit] = 0;
    }

    rep (j, (1 << w)) {
      vector<int> wBits(w);
      rep (bit, w) {
        if (j >> bit & 1) wBits[bit] = 1;
        else wBits[bit] = 0;
      }

      int sum = 0;
      rep (row, h) {
        if (hBits[row]) continue;
        rep (col, w) {
          if (!wBits[col] && graph[row][col] == '#') ++sum;
        }
      }
      if (sum == k) ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
