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

// https://atcoder.jp/contests/abc049/tasks/arc065_a

int main() {
  string s; cin >> s;
  reverse(s.begin(), s.end());
  vector<string> sub{"dream", "erase", "eraser", "dreamer"};
  rep (i, 4) reverse(sub[i].begin(), sub[i].end());
  while (!s.empty()) {
    bool ok = false;
    rep (i, 2) {
      if (s.size() >= 5 && s.substr(0, 5) == sub[i]) {
        ok = true;
        s = s.substr(5);
        break;
      }
    }
    if (ok) continue;
    if (s.size() >= 6 && s.substr(0, 6) == sub[2]) {
      s = s.substr(6);
      continue;
    }

    if (s.size() >= 7 && s.substr(0, 7) == sub[3]) {
      s = s.substr(7);
      continue;
    }

    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  return 0;
}