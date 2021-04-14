#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
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

const int INF = 1e9;
const ll INFL = 1e15;
const ll MOD = 1000000007;

// https://atcoder.jp/contests/abc134/tasks/abc134_e

/*
基本方針は複数あるであろう増加部分列の末尾の部分だけを管理する。

例: 2 1 4 5 3
増加増加列の遷移で考えると以下のようになる
[[2]] -> [[1] [2]] -> [[1] -> [2 4]] -> [[1] [2 4 5]] -> [[1 3] [2 4 5]]

増加部分列を全て管理する必要はないため増加部分列の末尾だけで管理する。
[2] -> [1 2] -> [1 4] -> [1 5] -> [3 5]

同じ数字も可能性として考えられること及び昇順になるためmultisetで管理する
*/
int main() {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  rep (i, n) cin >> a[i];
  multiset<int> dp;
  dp.emplace(a[0]);
  reps (i, 1, n) {
    auto it = dp.lower_bound(a[i]);
    if (it != dp.begin()) dp.erase(prev(it));
    dp.emplace(a[i]);
  }
  cout << dp.size() << endl;
  return 0;
}
