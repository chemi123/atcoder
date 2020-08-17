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

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_13_A&lang=ja

bool isAvailable(const vector<int>& rc, int row, int col) {
  rep (r, 8) {
    if (r == row || rc[r] == -1) continue;
    if (rc[r] == col) return false;
    if (abs(r - row) == abs(rc[r] - col)) return false;
  }
  return true;
}

vector<int> backtrack(vector<int> rc, int row) {
  if (row == 8) return rc;
  if (rc[row] != -1) return backtrack(rc, row + 1);

  rep (col, 8) {
    if (isAvailable(rc, row, col)) {
      vector<int> newrc(8, -1);
      copy(rc.begin(), rc.end(), newrc.begin());
      newrc[row] = col;
      vector<int> res = backtrack(newrc, row + 1);
      if (res.size() == 8) return res;
    }
  }

  return vector<int>(0);
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
  vector<int> res = backtrack(rc, 0);
  rep (r, 8) {
    string line;
    rep (i, 8) {
      if (i == res[r]) line += "Q";
      else line += ".";
    }
    cout << line << endl;;
  }

  return 0;
}
