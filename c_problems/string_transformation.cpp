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

// https://atcoder.jp/contests/abc110/tasks/abc110_c

/*
  変換不可は以下2つの条件を満たす時になる
  - s: "aa", t: "ab"のようにs内の同じ文字がt内で違う文字になっている場合
  - s: "ab", t: "aa"のようにt内の同じ文字がs内で違う文字になっている場合
*/
int main() {
  string s, t; cin >> s >> t;
  vector<vector<int>> amap(26), bmap(26);
  rep (i, s.size()) amap[s[i]-'a'].emplace_back(i);
  rep (i, t.size()) bmap[t[i]-'a'].emplace_back(i);
  rep (i, 26) {
    if (amap[i].size() < 2) continue;
    reps (j, 1, amap[i].size()) {
      if (t[amap[i][j]] != t[amap[i][0]]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  rep (i, 26) {
    if (bmap[i].size() < 2) continue;
    reps (j, 1, bmap[i].size()) {
      if (s[bmap[i][j]] != s[bmap[i][0]]) {
        cout << "No" << endl;
        return 0;
      }
    }
 }
  cout << "Yes" << endl;
  return 0;
}