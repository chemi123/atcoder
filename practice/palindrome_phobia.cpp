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

// https://atcoder.jp/contests/cf17-final/tasks/cf17_final_b

int main() {
  string s; cin >> s;
  pair<int, char> a = pair<int, char>(0, 'a'), b = pair<int, char>(0, 'b'), c = pair<int, char>(0, 'c');
  rep (i, s.size()) {
    if (s[i] == 'a') ++a.first; 
    else if (s[i] == 'b') ++b.first;
    else ++c.first;
  }

  vector<pair<int, char>> v{a, b, c};
  sort(v.begin(), v.end(), greater<pair<int, char>>());
  string str = string(1, v[0].second);
  --v[0].first;
  bool ok = true;

  reps (i, 1, s.size()) {
    sort(v.begin(), v.end(), greater<pair<int, char>>());
    rep (j, 3) {
      if (v[j].first == 0) continue;
      if (v[j].second == str[i-1]) continue;
      if (str.size() >= 2 && v[j].second == str[i-2]) continue;
      str += v[j].second;
      --v[j].first;
      break;
    }
    if (str.size() != i + 1) {
      ok = false;
      break;
    }
  }
  if (ok) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}