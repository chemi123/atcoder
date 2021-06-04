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

// https://atcoder.jp/contests/abc193/tasks/abc193_c

int main() {
  ll n; cin >> n;
  unordered_set<ll> s;
  reps (a, 2, 1e5 + 1) {
    if (pow(a, 2) > n) break;
    reps (b, 2, 50) {
      ll ab = (ll)pow(a, b);
      if (ab > n) break;
      s.emplace(ab);
    }
  }
  cout << n - s.size() << endl;
  return 0;
}
