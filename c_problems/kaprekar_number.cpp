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

// https://atcoder.jp/contests/abc192/tasks/abc192_c

int g1(int x) {
  string s = to_string(x);
  vector<int> v;
  rep (i, s.size()) v.emplace_back(s[i] - '0');
  sort(v.begin(), v.end());
  int res = 0;
  rep (i, v.size()) res += (v[i] * pow(10, i));
  return res;
}

int g2(int x) {
  string s = to_string(x);
  vector<int> v;
  rep (i, s.size()) v.emplace_back(s[i] - '0');
  sort(v.begin(), v.end(), greater());
  int res = 0;
  rep (i, v.size()) res += (v[i] * pow(10, i));
  return res;
}

int f(int x) { return g1(x) - g2(x); }

int main() {
  int n, k; cin >> n >> k;
  rep (i, k) n = f(n);
  cout << n << endl;
  return 0;
}
