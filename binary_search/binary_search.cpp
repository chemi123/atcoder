#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B

bool binarySearch(const std::vector<int>& s, int target) {
  int ok = (int)s.size();
  int ng = -1;

  while (ok - ng > 1) {
    int mid = (ok + ng) / 2;
    if (s[mid] == target) {
      return true;
    } else if (s[mid] > target) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  return false;
}

int main() {
  int n, q;
  cin >> n;
  vector<int> s(n, 0);
  rep (i, n) cin >> s[i];

  cin >> q;
  vector<int> t(q, 0);
  rep (i, q) cin >> t[i]; 

  int ans = 0;
  rep (i, q) {
    if (binarySearch(s, t[i])) ++ans;
  }
  cout << ans << endl;
  return 0;
}