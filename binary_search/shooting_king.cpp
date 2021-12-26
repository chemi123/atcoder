#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

// https://atcoder.jp/contests/abc023/tasks/abc023_d

bool check(const vector<ll>& h, const vector<ll>& s, ll mid, int n) {
  vector<ll> timeLimits(n, 0);
  rep (i, n) {
    if (h[i] > mid) return false;
    timeLimits[i] = (mid - h[i]) / s[i];
  }
  sort(timeLimits.begin(), timeLimits.end());
  rep (i, n) {
    if (timeLimits[i] < i) return false;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<ll> h(n, 0), s(n, 0);
  rep (i, n) cin >> h[i] >> s[i];
  ll ng = -1, ok = 1e15;
  while (ok - ng > 1) {
    ll mid = (ok + ng) / 2;
    if (check(h, s, mid, n)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}