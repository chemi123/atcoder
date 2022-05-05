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

class Combination {
public:
  const long long COMBI_MOD = 1000000007;

  Combination(int n) :
    _fac(vector<long long>(n + 1)),
    _finv(vector<long long>(n + 1)),
    _inv(vector<long long>(n + 1)) {
    _fac[0] = 1, _fac[1] = 1;
    _finv[0] = 1, _finv[1] = 1;
    _inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
      _fac[i] = _fac[i-1] * i % COMBI_MOD;
      _inv[i] = COMBI_MOD - _inv[COMBI_MOD%i] * (COMBI_MOD / i) % COMBI_MOD;
      _finv[i] = _finv[i - 1] * _inv[i] % COMBI_MOD;
    }
  }

  long long com(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return _fac[n] * (_finv[k] * _finv[n - k] % COMBI_MOD) % COMBI_MOD;
  }

private:
  vector<long long> _fac;
  vector<long long> _finv;
  vector<long long> _inv;
};

int main() {
  Combination combi(10);
  cout << combi.com(5, 3) << endl;
  return 0;
}