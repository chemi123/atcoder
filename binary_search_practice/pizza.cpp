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

int binarySearch(const vector<int>& s, int target) {
  int ok = (int)s.size(), ng = -1;
  while (ok - ng > 1) {
    int mid = (ok + ng) / 2;
    if (s[mid] == target) {
      return mid;
    } else if (s[mid] > target) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

int main() {
  int d, n, m;
  cin >> d >> n >> m;
  vector<int> s(n, 0), t(m, 0);
  for (int i = 1; i < n; ++i) cin >> s[i];
  rep (i, m) cin >> t[i];
  sort(s.begin(), s.end());
  int res = 0;
  rep (i, m) {
    int index = binarySearch(s, t[i]);
    if (index == (int)s.size()) {
      res += min(abs(s[index-1]-t[i]), abs(d-t[i]));
    } else {
      res += min(abs(s[index-1]-t[i]), abs(s[index]-t[i]));
    }
  }
  cout << res << endl;
  return 0;
}
