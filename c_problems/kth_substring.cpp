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

// https://atcoder.jp/contests/abc097/tasks/arc097_a

int main() {
  string s; cin >> s;
  int k; cin >> k;
  if (s.size() > 5) {
    vector<string> v;
    rep (l, s.size() - 4) v.emplace_back(s.substr(l, 5));
    sort(v.begin(), v.end());
    s = v[0];
  }

  set<string> ans;
  rep (l, s.size()) reps (i, 1, s.size() - l + 1) ans.emplace(s.substr(l, i));

  int i = 0;
  for (auto e : ans) {
    if (i == k - 1) {
      cout << e << endl;
      break;
    }
    ++i;
  }
  return 0;
}