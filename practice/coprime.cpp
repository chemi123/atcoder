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

// https://atcoder.jp/contests/abc177/tasks/abc177_e

void getPrimeNumbers(set<int>& s, int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i != 0) continue;
    while (n % i == 0) n /= i;
    s.emplace(i);
  }
  if (n != 1) s.emplace(n);
}

int main() {
  int n; cin >> n;
  int A = 1000001;
  vector<int> a(n);
  vector<int> cnt(A);
  set<int> s;
  rep (i, n) {
    cin >> a[i];
    ++cnt[a[i]];
    getPrimeNumbers(s, a[i]);
  }
  bool ok = true;
  for (auto e : s) {
    int c = 0;
    for (int i = e; i < A; i += e) {
      if (cnt[i]) ++c;
      if (cnt[i] > 1) ok = false;
    }
    if (c > 1) {
      ok = false;
      break;
    }
  }
  if (ok) cout << "pairwise coprime" << endl;
  else {
    int g = a[0];
    reps (i, 1, n) g = gcd(g, a[i]);
    if (g == 1) cout << "setwise coprime" << endl;
    else cout << "not coprime" << endl;
  }
  return 0;
}