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
#define reps(i, s, n) for (int i = s; i < n; i++)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

const int INF = 1e9;
const ll INFL = 1e15;
const ll MOD = 1000000007;

// https://atcoder.jp/contests/abc006/tasks/abc006_4

int main() {
  int n;
  cin >> n;
  vector<int> trump(n, 0);
  rep (i, n) cin >> trump[i];
  vector<int> dp(1, trump[0]);
  dp.reserve(n);
  reps (i, 1, n) {
    if (dp[(int)dp.size()-1] < trump[i]) dp.emplace_back(trump[i]);
    else *lower_bound(dp.begin(), dp.end(), trump[i]) = trump[i];
  }
  cout << n - (int)dp.size() << endl;
  return 0;
}
