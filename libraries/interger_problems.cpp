#include <iostream>
#include <map>
#include <set>

using ll = long long;

using namespace std;

// 素数列挙
void enumeratePrime(map<ll, ll>& m, ll n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i != 0) continue;
    ll cnt = 0;
    while (n % i == 0) {
      ++cnt;
      n /= i;
    }
    m[i] = cnt;
  }

  if (n != 1) m[n] = 1;
}

// 約数列挙
void enumerateDivisor(set<ll>& m, ll n) {
  for (int i = 1; i * i <= n; ++i) {
    if (n % i != 0) continue;
    m.emplace(i);
    if (i * i != n) m.emplace(n/i);
  }
}

int main() {
  map<ll, ll> m1;
  ll n = 200;
  enumeratePrime(m1, n);
  for (auto [num, cnt] : m1) cout << num << ": " << cnt << endl; 
  cout << endl;

  set<ll> m2;
  enumerateDivisor(m2, n);
  for (auto e : m2) cout << e << endl; 
  return 0;
}