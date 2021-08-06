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

// https://atcoder.jp/contests/abc058/tasks/arc071_a

int main() {
  int n; cin >> n;
  int size = 26;
  vector<int> m(size);
  rep (i, n) {
    string s; cin >> s;
    vector<int> tmp(size);
    rep (j, s.size()) ++tmp[s[j]-'a'];
    if (i == 0) m = tmp;
    else {
      rep (j, size) m[j] = min(m[j], tmp[j]);
    }
  }
  string ans;
  rep (i, size) if (m[i] > 0) rep (j, m[i]) ans += (char)(i + 'a');
  cout << ans << endl;
  return 0;
}