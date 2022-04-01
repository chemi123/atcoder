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

// https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_c

struct PairComparere {
  const bool operator() (const pi& left, const pi& right) {
    return left.first + left.second < right.first + right.second;
  }
};

int main() {
  int n; cin >> n;
  priority_queue<pi, vector<pi>, PairComparere> pq;
  rep (i, n) {
    int a, b; cin >> a >> b;
    pq.emplace(pi(a, b));
  }

  ll ans = 0;
  rep (i, n) {
    auto [a, b] = pq.top(); pq.pop();
    if (i % 2 == 0) ans += a;
    else ans -= b;
  }
  cout << ans << endl;
  return 0;
}