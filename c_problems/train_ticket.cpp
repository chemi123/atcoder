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

// https://atcoder.jp/contests/abc079/tasks/abc079_c

int main() {
  string str; cin >> str;
  vector<int> abcd(4);
  rep (i, 4) abcd[i] = str[i] - '0';
  rep (i, 1 << 3) {
    int sum = abcd[0];
    rep (j, 3) {
      if (i >> j & 1) sum += abcd[j+1];
      else sum -= abcd[j+1];
    }

    if (sum == 7) {
      cout << abcd[0];
      rep (j, 3) {
        if (i >> j & 1) cout << "+";
        else cout << "-";
        cout << abcd[j+1];
      }
      cout << "=7" << endl;
      break;
    }
  }
  return 0;
}