#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
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

// https://atcoder.jp/contests/abc200/tasks/abc200_e

ll c1(ll s) {
  if (s <= 0) return 0;
  return s;
}

ll c2(ll s) {
  if (s <= 0) return 0;
  return s * (s - 1) / 2;
}

int main() {
  ll n, k; cin >> n >> k;
  /*
    f1(s)はa + b + c = sのとなるa, b, cの組み合わせの数　
    1 <= a, b, c <= nの制約を満たす必要があるため包除の原理で求める。
    とりあえずa, b, c >= 0の制約であればa + b + cを満たす組み合わせは(s + 2)C2となる。
    a, b, c >= 1の制約であれば(a - 1) + (b - 1) + (c - 1) = (s - 3)となる組み合わせで考えられるため、(s + 2 -3 )C2 == (s - 1)C2で求められる。
    ここでa + b + c = sを満たすが、a, b, c <= nを満たさないa, b, cの組み合わせは以下の7通りが考えられる。(geはgreater or equalの略)
    (a, b, c) = [(ge(n + 1), ge(n + 1), ge(n + 1)),
                 ((ge(n + 1), ge(n + 1), ge(1)),
                 ((ge(n + 1), ge(1), ge(n + 1)),
                 ((ge(1), ge(n + 1), ge(n + 1)),
                 ((ge(n + 1), ge(1), ge(1)),
                 ((ge(1), ge(n + 1), ge(1)),
                 ((ge(1), ge(1), ge(n + 1))]
    ge(n + 1)が1つの組み合わせはa, b, c >= 1の制約で考えた時と同様に考えると(a - (n + 1)) - (b - 1) + (c - 1) = (s - n - 3)なので、(s + 2 - n - 3) == (s - n - 1)C2で求められる。
    ge(n + 1)が1つになるのは((ge(1), ge(1), ge(n + 1)), ((ge(1), ge(n + 1), ge(1)), ((ge(n + 1), ge(1), ge(1))の三通りあるため(s - n - 1)C2 * 3となる。
    ge(n + 1)が２つになる組み合わせは同様に考えれば(s - 2 * n - 1)C2 * 3通り。
    ge(n + 1)が3つになる組み合わせは(s - 3 * n - 1)C2通り。
    ここで包除の原理により
    f1(s) = (s - 1)C2 - (s - n - 1)C2 * 3 + (s - 2 * n - 1)C2 * 3 - (s - 3 * n - 1)C2
  */
  auto f1 = [&n](ll s) -> ll {
    return c2(s - 1) - c2(s - n - 1) * 3 + c2(s - 2 * n - 1) * 3 - c2(s - 3 * n - 1);
  };

  /*
    考え方はf1と同じ。こっちの方が簡単。
    b + c = sとなる個数をf2(s)として定義。f1と同じように考えると、b, c >= 1の場合、
    b + c = sを満たす組み合わせは(s - 1)C1通りある。
    b + c = sを満たすがb, c <= nを満たさないb, cの組は以下の3通りで考えられる
    (b, c) = [ge(n + 1), ge(n + 1),
              ge(n + 1), ge(1),
              ge(1), ge(n + 1)]
    ge(n + 1)が2つある組み合わせは(s - 2 * n - 1)C1通り、
    ge(n + 1)が1つある組み合わせは(s - n - 1)C1 * 2通り。
    ge(n + 1)が1つある組み合わせは2つある組み合わせを含むため、f1と同じように包除の原理により
    f2(s) = (s - 1)C1 - (s - n - 1) * 2 + (s - 2 * n - 1)C1
  */
  auto f2 = [&](ll s) -> ll {
    return c1(s - 1) - c1(s - n - 1) * 2 + c1(s - 2 * n - 1);
  };
  reps (s, 1, 3 * n + 1) {
    ll x = f1(s);
    if (k > x) {
      k -= x;
      continue;
    }

    reps (a, 1, n + 1) {
      x = f2(s - a);
      if (k > x) {
        k -= x;
        continue;
      }
      reps (b, 1, n + 1) {
        int c = s - a - b;
        if (c < 0 || c > n) continue;
        if (k == 1) {
          cout << a << " " << b << " " << c << endl;
          return 0;
        }
        --k;
      }
    }
  }
  return 0;
}