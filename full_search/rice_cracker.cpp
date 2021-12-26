#include <iostream>
#include <vector>

using namespace std;

// https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_e

int main() {
  int r, c;
  cin >> r >> c;
  vector<vector<int>> rc(r, vector(c, 0));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> rc[i][j];
    }
  }

  int ans = 0;
  for (int bit = 0; bit < (1 << r); ++bit) {

    vector<bool> isFlipped(r, false);
    for (int row = 0; row < r; ++row) {
      if (bit & (1 << row)) isFlipped[row] = true;
    }

    int total = 0;
    for (int col = 0; col < c; ++col) {
      int flipped = 0;
      for (int row = 0; row < r; ++row) {
        if (isFlipped[row] && rc[row][col] == 1) ++flipped;
        else if (!isFlipped[row] && rc[row][col] == 0) ++flipped;
      }
      if (flipped > r / 2) total += flipped;
      else total += (r - flipped);
    }
    ans = max(ans, total);
  }
  cout << ans << endl;
  return 0;
}