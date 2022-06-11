#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
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

// あえてベクトルを分けて考えている
// https://atcoder.jp/contests/abc197/tasks/abc197_d

int main() {
  double n; cin >> n;
  double theta = 2 * M_PI / n;
  double x, y; cin >> x >> y;

  // 点A(x0, y0)
  complex<double> a = {x, y};
  cin >> x >> y;

  // 点B(x2/n, y2/n)
  complex<double> b = {x, y};

  // AとBの中心点P
  auto p = (a + b) / 2.0;

  // ベクトルPA
  auto pa = a - p;

  // ベクトルPB(PAを中心角θとして回転したもの)
  auto pb = pa * polar(1.0, theta);

  auto ans = p + pb;

  cout << fixed << setprecision(10) << ans.real() << " " << ans.imag() << endl;

  return 0;
}