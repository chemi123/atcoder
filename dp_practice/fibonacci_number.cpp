#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_A&lang=ja

int fibonacci(unordered_map<int, int>& m, int n) {
  if (n == 0 || n == 1) return 1;
  auto it = m.find(n);
  if (it != m.end()) return it->second;
  m[n] = fibonacci(m, n - 1) + fibonacci(m, n - 2);
  return m[n];
}

int main() {
  int n;
  cin >> n;
  unordered_map<int, int> m;
  cout << fibonacci(m, n) << endl;
  return 0;
}
