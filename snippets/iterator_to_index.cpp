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

// イテレーターの指すindexを取る方法
void iterator_to_index() {
  vector<int> v{1, 2, 3, 4, 5};
  auto it = lower_bound(v.begin(), v.end(), 3);
  int index = it - v.begin();
  cout << index << endl;
}

int main() {
  iterator_to_index();
  return 0;
}