#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
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

// https://atcoder.jp/contests/abc155/tasks/abc155_c

int main() {
  int n; cin >> n;
  map<string, int> m;
  int maxFreq = 0;
  rep (i, n) {
    string s; cin >> s;
    ++m[s];
    maxFreq = max(maxFreq, m[s]);
  }
  set<string> s;
  for (const auto& [str, freq] : m) {
    if (freq != maxFreq) continue;
    s.emplace(str);
  }
  for (auto ans : s) cout << ans << endl;
  return 0;
}
