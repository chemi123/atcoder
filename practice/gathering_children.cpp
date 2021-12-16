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

// https://atcoder.jp/contests/abc136/tasks/abc136_d

int main() {
  string s; cin >> s;
  int n = (int)s.size();
  vector<int> RtoL((int)s.size(), -1), LtoR((int)s.size(), -1);
  rep (i, n) {
    if (s[i] == 'L') continue;
    if (i > 0 && RtoL[i-1] != -1) {
      RtoL[i] = RtoL[i-1] - 1;
      continue;
    }
    reps (j, i + 1, n) {
      if (s[j] == 'L') {
        RtoL[i] = j - i;
        break;
      }
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == 'R') continue;
    if (i < n - 1 && LtoR[i+1] != -1) {
      LtoR[i] = LtoR[i+1] - 1;
      continue;
    }
    for (int j = i - 1; j >= 0; --j) {
      if (s[j] == 'R') {
        LtoR[i] = i - j;
        break;
      }
    }
  }
  vector<int> ans(n);
  rep (i, n) {
    if (RtoL[i] == -1) continue;
    if (RtoL[i] % 2 == 0) ++ans[i + RtoL[i]];
    else ++ans[i + RtoL[i] - 1];
  }

  rep (i, n) {
    if (LtoR[i] == -1) continue;
    if (LtoR[i] % 2 == 0) ++ans[i - LtoR[i]];
    else ++ans[i - LtoR[i] + 1];
  }
  for (auto e : ans) cout << e << " "; cout << endl;
  return 0;
}