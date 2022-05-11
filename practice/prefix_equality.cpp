#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
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

// https://atcoder.jp/contests/abc250/tasks/abc250_e

template<int MOD> struct ModInt {
    static const int Mod = MOD; unsigned x; ModInt() : x(0) { }
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const { long long a = x, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return ModInt(u); }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ostream& operator<<(ostream& st, const ModInt<MOD> a) { st << a.get(); return st; };
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
    ModInt<MOD> r = 1; while (k) { if (k & 1) r *= a; a *= a; k >>= 1; } return r; }
typedef ModInt<1000000007> mint;
const mint BASE = 1007;

mint modPow(const mint &a, long long n) {
  if (n == 0) return 1;
  auto t = modPow(a, n / 2);
  t = t * t;
  if (n & 1) t = t * a;
  return t;
}

void calcHash(const vector<int>& v, vector<mint>& hash) {
  set<int> s;
  s.emplace(v[0]);
  hash[0] = modPow(BASE, v[0]);
  reps (i, 1, v.size()) {
    if (s.find(v[i]) == s.end()) {
      s.emplace(v[i]);
      hash[i] = hash[i-1] + modPow(BASE, v[i]);
    } else {
      hash[i] = hash[i-1];
    }
  }
}

int main() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  rep (i, n) cin >> a[i];
  rep (i, n) cin >> b[i];
  int q; cin >> q;
  vector<mint> hashA(n), hashB(n);
  calcHash(a, hashA);
  calcHash(b, hashB);
  rep (i, q) {
    int x, y; cin >> x >> y; --x, --y;
    if (hashA[x] == hashB[y]) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}