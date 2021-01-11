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

bool isValid(const vector<int>& rc, int row, int col) {
  rep (r, 8) {
    if (r == row || rc[r] == -1) continue;
    if (rc[r] == col) return false;
    if (abs(r - row) == abs(rc[r] - col)) return false;
  }
  return true;
}

bool backtrack(vector<int>& rc, int r) {
  if (r == 8) return true;
  if (rc[r] != -1) return backtrack(rc, r + 1);
  rep (c, 8) {
    if (isValid(rc, r, c)) {
      rc[r] = c;
      if (backtrack(rc, r + 1)) return true;
    }
  }
  rc[r] = -1;
  return false;
}

int main() {
  int k;
  cin >> k;
  vector<int> rc(8, -1);
  rep (i, k) {
    int r, c;
    cin >> r >> c;
    rc[r] = c;
  }
  backtrack(rc, 0);
  rep (i, 8) {
    string c_str("........");
    c_str[rc[i]] = 'Q';
    cout << c_str << endl;
  }
  return 0;
}
