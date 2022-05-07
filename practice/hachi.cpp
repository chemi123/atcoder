#include <algorithm>
#include <bitset>
#include <cassert>
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

// https://atcoder.jp/contests/abc181/tasks/abc181_d

int main() {
  string s; cin >> s;
  if (s.size() == 1) {
    if (s == "8") cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
  }

  if (s.size() == 2) {
    string s2 = s;
    reverse(s2.begin(), s2.end());
    int n1 = stoi(s), n2 = stoi(s2);
    if (n1 % 8 == 0 || n2 % 8 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
  }

  vector<int> cnt(10);
  rep (i, s.size()) ++cnt[s[i]-'0'];
  reps (i, 100, 1000) {
    if (i % 8 != 0) continue;
    string si = to_string(i);
    vector<int> siCnt(10);
    rep (j, si.size()) ++siCnt[si[j]-'0'];

    bool ok = true;
    rep (j, 10) if (siCnt[j] > cnt[j]) ok = false;
    if (ok) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}