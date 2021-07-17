#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

// https://atcoder.jp/contests/abc093/tasks/arc094_a

int main() {
  vector<int> abc(3);
  rep (i, 3) cin >> abc[i];
  sort(abc.begin(), abc.end());
  bool ac = (abc[0] % 2 == abc[2] % 2);
  bool bc = (abc[1] % 2 == abc[2] % 2);

  if (ac && bc) cout << (abc[2] - abc[0]) / 2 + (abc[2] - abc[1]) / 2 << endl;
  if (ac && !bc) cout << (abc[2] - abc[0]) / 2 + (abc[2] + 1 - abc[1]) / 2 + 1 << endl;
  if (!ac && bc) cout << (abc[2] + 1 - abc[0]) / 2 + (abc[2] - abc[1]) / 2 + 1 << endl;
  if (!ac && !bc) cout << (abc[2] - abc[0]) / 2 + (abc[2] - abc[1]) / 2 + 1 << endl;
  return 0;
}