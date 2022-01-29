#include <algorithm>
#include <bitset>
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

int main() {
  map<vector<int>, bool> m;
  vector v1{1, 2, 3};
  vector v2{1, 2};
  vector v3{2, 2, 3};
  m[v1] = 1;
  m[v2] = 2;
  m[v3] = 0;
  vector v{1, 2, 3};
  cout << m[v] << endl;
  v = vector{1, 2};
  cout << m[v] << endl;
  v = vector{2, 2, 3};
  cout << m[v] << endl;
  return 0;
}