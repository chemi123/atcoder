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

// https://atcoder.jp/contests/abc146/tasks/abc146_c

int main() {
  ll a, b, x; cin >> a >> b >> x;
  ll ok = 0, ng = 1e9 + 1;
  while (abs(ok - ng) > 1) {
    ll n = (ok + ng) / 2;
    ll cost = a * n + b * to_string(n).size(); 
    if (cost <= x) ok = n;
    else ng = n;
  }
  cout << ok << endl;
  return 0;
}
