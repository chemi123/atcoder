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

// https://atcoder.jp/contests/arc008/tasks/arc008_2

int main() {
  int n, m; cin >> n >> m;
  string name, kit; cin >> name >> kit;
  vector<int> nmap(26), kmap(26);
  rep (i, n) ++nmap[name[i] - 'A'];
  rep (i, m) ++kmap[kit[i] - 'A'];
  int ans = 0;
  rep (i, 26) {
    if (nmap[i] == 0) continue;
    if (kmap[i] == 0) {
      cout << -1 << endl;
      return 0;
    }
    int m = nmap[i] / kmap[i];
    if (nmap[i] % kmap[i] != 0) ++m;
    ans = max(ans, m);
  }
  cout << ans << endl;
  return 0;
}