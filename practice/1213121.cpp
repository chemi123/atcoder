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

string rec(int n, unordered_map<int, string>& m) {
  if (n == 1) return "1";
  if (m.find(n) != m.end()) return m[n];
  string res = rec(n - 1, m) + " " + to_string(n) + " " + rec(n - 1, m); 
  m[n] = res;
  return res;
}

int main() {
  int n; cin >> n;
  unordered_map<int, string> m;
  cout << rec(n, m) << endl;
  return 0;
}