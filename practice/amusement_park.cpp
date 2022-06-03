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

// https://atcoder.jp/contests/abc216/tasks/abc216_e

ll sum(ll n) {
  return n * (n + 1) / 2;
}

int main() {
  int n, k; cin >> n >> k;
  map<ll, ll> m;
  rep (i, n) {
    ll a; cin >> a;
    ++m[a];
  }

  vector<pl> numCnt;
  for (auto [num, cnt] : m) numCnt.emplace_back(pl(num, cnt));
  sort(numCnt.rbegin(), numCnt.rend());
  numCnt.emplace_back(pl(0, 0));

  ll ans = 0;
  rep (i, numCnt.size() - 1) {
    auto& [num, cnt] = numCnt[i];
    auto& [next_num, next_cnt] = numCnt[i+1];
    ll deduct_cnt = (num - next_num) * cnt;
    if (k >= deduct_cnt) {
      k -= deduct_cnt;
      ans += (sum(num) - sum(next_num)) * cnt;
      next_cnt += cnt;
      continue;
    }

    ans += (sum(num) - sum(num - (k / cnt))) * cnt + (num - (k / cnt)) * (k % cnt);
    cout << ans << endl;
    return 0;
  }

  cout << ans << endl;
  return 0;
}