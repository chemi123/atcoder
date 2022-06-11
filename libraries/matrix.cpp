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

pair<double, double> affin_transformation(double x, double y, double radian, double scaleX, double scaleY, double translationX, double translationY) {
  double retX = scaleX * cos(radian) * x - sin(radian) * y + translationX;
  double retY = sin(radian) * x + scaleY * cos(radian) * y + translationY;
  return {retX, retY};
}

pair<double, double> rotate(double x, double y, double radian) {
  double retX = cos(radian) * x - sin(radian) * y;
  double retY = sin(radian) * x + cos(radian) * y;
  return {retX, retY};
}

pair<double, double> scale(double x, double y, double scaleX, double scaleY) {
  return {x * scaleX, y * scaleY};
}

int main() {
  auto [x, y] = affin_transformation(0, 1, -M_PI / 3, 1.0, 1.0, 0, 0);
  cout << x << " " << y << endl;
  return 0;
}