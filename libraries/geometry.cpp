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

// 二点を通る直線上にあるかどうかの判定
bool onSameLine(int x1, int y1, int x2, int y2, int x3, int y3) {
  if (x1 == x2) return x3 == x1;
  if (y1 == y2) return y3 == y1;
  return (y3 - y1) * (x2 - x1) == (y2 - y1) * (x3 - x1);
}

int main() {
  return 0;
}