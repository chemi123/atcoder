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

const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1000000007;

// https://atcoder.jp/contests/abc076/tasks/abc076_c

int main() {
  string s, t; cin >> s >> t;
  bool ok = false;
  int l = 0;
  rep (i, s.size() - t.size() + 1) {
    string sub = s.substr(i, t.size());
    rep (j, t.size()) {
      if (sub[j] != t[j] && sub[j] != '?') break;
      if (j == t.size()  - 1) {
        ok = true, l = i;
      }
    }
  }
  if (!ok) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  reps (i, l, l + t.size()) s[i] = t[i-l];
  rep (i, s.size()) if (s[i] == '?') s[i] = 'a';
  cout << s << endl;
  return 0;
}