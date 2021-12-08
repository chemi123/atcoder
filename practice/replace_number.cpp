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

// クソコード
// https://atcoder.jp/contests/abc033/tasks/abc033_c

int main() {
  string s; cin >> s;
  if (s.size() == 1) {
    if (s == "0") cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
  }
  vector<int> pindex;
  rep (i, s.size()) if (s[i] == '+') pindex.emplace_back(i);

  if (pindex.size() == 0) {
    bool ok = true;
    for (int i = 0; i < (int)s.size(); i += 2) {
      if (s[i] == '0') {
        ok = false;
        break;
      }
    }
    if (ok) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
  }

  int ans = 0;
  int l = -1;
  for (auto r : pindex) {
    if (r - l == 2) {
      if (s[l+1] != '0') ++ans;
      l = r;
      continue;
    }
    bool ok = true;
    for (int i = l + 1; i < r; i += 2) {
      if (s[i] == '0') {
        ok = false;
        break;
      }
    }
    if (ok) ++ans;
    l = r;
  }
  if (pindex.back() == (int)s.size() - 2) {
    if (s[pindex.back()+1] != '0') ++ans;
  } else {
    bool ok = true;
    for (int i = pindex.back() + 1; i < (int)s.size(); i += 2) {
      if (s[i] == '0') {
        ok = false;
        break;
      }
    }
    if (ok) ++ans;
  }
  cout << ans << endl;
  return 0;
}