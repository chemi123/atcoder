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

mint modPow(const mint &a, long long n) {
  if (n == 0) return 1;
  auto t = modPow(a, n / 2);
  t = t * t;
  if (n & 1) t = t * a;
  return t;
}

// modを使った簡単なhash
// vector格納されているユニークな数の集合をhashに変換
// 衝突する確率はものによるが計算が間違ってなければユニークな数が2 * 10^5で約37%
// ただし以下の問題で全テストケースが通ったため、もっと低い可能性がある。
// https://atcoder.jp/contests/abc250/tasks/abc250_e
// 
// いずれにせよvector内の集合のhashとして簡単に使うことはできるが、過信は禁物
const mint BASE = 1007;
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