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

// https://atcoder.jp/contests/abc064/tasks/abc064_c

int main() {
  int n; cin >> n;
  set<int> s;
  int freeColor = 0;
  rep (i, n) {
    double a; cin >> a; 
    a = a / 400;
    if (a >= 8) ++freeColor;
    else s.emplace((int)a);
  }
  int ansMin = (int)s.size();
  if (s.size() == 0 && freeColor > 1) ansMin = 1;
  cout << ansMin << " " << (int)s.size() + freeColor << endl;
  return 0;
}