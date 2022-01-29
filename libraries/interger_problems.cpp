#include <iostream>
#include <map>
#include <set>
#include <vector>

using ll = long long;

using namespace std;

// 素因数分解
void primeFactorization(map<ll, ll>& s, ll n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i != 0) continue;
    ll cnt = 0;
    while (n % i == 0) {
      ++cnt;
      n /= i;
    }
    s[i] = cnt;
  }

  if (n != 1) s[n] = 1;
}

// 約数列挙
void enumerateDivisor(set<ll>& s, ll n) {
  for (int i = 1; i * i <= n; ++i) {
    if (n % i != 0) continue;
    s.emplace(i);
    if (i * i != n) s.emplace(n/i);
  }
}

// エラトステネスの篩
void eratosthenes(vector<ll>& primes, ll n) {
  vector<int> cnt(n + 1);
  for (ll i = 2; i * i <= n; ++i) {
    if (cnt[i] > 0) continue;
    for (ll j = 2; i * j <= n; ++j) cnt[i * j] = 1;
  }
  for (int i = 2; i <= n; ++i) if (cnt[i] == 0) primes.emplace_back(i);
}

// 桁数
int getDigit(int num) {
  return log10(num) + 1;
}

int main() {
  map<ll, ll> s1;
  ll n = 200;
  primeFactorization(s1, n);
  for (auto [num, cnt] : s1) cout << num << ": " << cnt << endl; 
  cout << endl;

  set<ll> s2;
  enumerateDivisor(s2, n);
  for (auto e : s2) cout << e << endl; 
  cout << endl;

  vector<ll> v;
  eratosthenes(v, 100);
  for (auto e : v) cout << e << " "; cout << endl;
  return 0;
}