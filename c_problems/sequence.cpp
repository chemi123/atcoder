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

// https://atcoder.jp/contests/abc059/tasks/arc072_a

int main() {
  int n; cin >> n;
  vector<ll> acc(n);
  vector<ll> a(n);
  rep (i, n) {
    cin >> a[i];
    if (i == 0) acc[i] = a[i];
    else acc[i] = acc[i-1] + a[i];
  }

  ll cnt = 0, sum = 0;
  if (acc[0] <= 0) {
    sum += (-acc[0] + 1);
    cnt += abs(sum);
    acc[0] += sum;
  }
  reps (i, 1, n) {
    bool plus = (acc[i-1] < 0) ? true : false;
    ll cur = acc[i] + sum;
    if (plus) {
      if (cur <= 0) {
        sum += (-cur + 1);
        cnt += (-cur + 1);
      }
    } else {
      if (cur >= 0) {
        sum += (-cur - 1);
        cnt += (cur + 1);
      }
    }
    acc[i] += sum;
  }

  acc[0] = a[0];
  reps (i, 1, n) acc[i] = acc[i-1] + a[i];

  ll ans = cnt;
  cnt = 0, sum = 0;
  if (acc[0] >= 0) {
    sum += (-acc[0] - 1);
    cnt += abs(sum);
    acc[0] += sum;
  }
  reps (i, 1, n) {
    bool plus = (acc[i-1] < 0) ? true : false;
    ll cur = acc[i] + sum;
    if (plus) {
      if (cur <= 0) {
        sum += (-cur + 1);
        cnt += (-cur + 1);
      }
    } else {
      if (cur >= 0) {
        sum += (-cur - 1);
        cnt += (cur + 1);
      }
    }
    acc[i] += sum;
  }
  ans = min(ans, cnt);
  cout << ans << endl;
  return 0;
}