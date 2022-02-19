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

// https://atcoder.jp/contests/dp/tasks/dp_q

template <typename T>
class SegmentTree {
public:
  const T SEGMENT_TREE_INF = numeric_limits<T>::max();
  SegmentTree(vector<T>& v) {
    _n = 1;
    while (_n < (int)v.size()) _n *= 2;
    _nodes.resize(2 * _n - 1, 0);

    for (int i = 0; i <(int)v.size(); ++i) _nodes[_n-1+i] = v[i];
    for (int i = _n - 2; i >= 0; --i) _nodes[i] = max(_nodes[2*i+1], _nodes[2*i+2]);
  }

  void update(int index, T val) {
    int x = index + _n - 1;
    _nodes[x] = val;
    while (x > 0) {
      x = (x - 1) / 2;
      _nodes[x] = max(_nodes[2*x+1], _nodes[2*x+2]);
    }
  }

  T query(int a, int b) { return query_sub(a, b, 0, 0, _n); }

private:
  T query_sub(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return 0;
    else if (a <= l && r <= b) return _nodes[k];
    return max(query_sub(a, b, 2 * k + 1, l, (l + r) / 2), query_sub(a, b, 2 * k + 2, (l + r) / 2, r));
  }

  int _n;
  vector<T> _nodes;
};

int main() {
  int n; cin >> n;
  vector<ll> h(n), a(n);
  rep (i, n) cin >> h[i];
  rep (i, n) cin >> a[i];
  vector<ll> dp(n + 1, 0);
  dp[h[0]] = a[0];
  SegmentTree st(dp);
  reps (i, 1, n) {
    dp[h[i]] = st.query(0, h[i] + 1) + a[i];
    st.update(h[i], dp[h[i]]);
  }
  ll ans = 0;
  for (auto& e : dp) ans = max(ans, e);
  cout << ans << endl;
  return 0;
}