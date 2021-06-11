#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

// https://atcoder.jp/contests/abc187/tasks/abc187_c

int main() {
  int n; cin >> n;
  vector<string> a(n);
  unordered_set<string> ums;
  rep (i, n) {
    cin >> a[i];
    ums.emplace(a[i]);
  }
  for (auto s : a) {
    if (ums.find("!" + s) != ums.end()) {
      cout << s << endl;
      return 0;
    }
  }
  cout << "satisfiable" << endl;
  return 0;
}
