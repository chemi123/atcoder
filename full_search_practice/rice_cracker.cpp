#include <iostream>
#include <vector>

using namespace std;

// https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_e

void copyVec(const vector<vector<int>>& vec1, vector<vector<int>>& vec2) {
  for (size_t i = 0; i < vec1.size(); ++i) {
    for (size_t j = 0; j < vec1[0].size(); ++j) {
      vec2[i][j] = vec1[i][j];
    }
  }
}

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
    vector<vector<int>> rcCpy(r, vector(c, 0));
    copyVec(rc, rcCpy);

    for (int row = 0; row < r; ++row) {
      if (bit & (1 << row)) {
        for (int col = 0; col < (int)rcCpy[row].size(); ++col) {
          if (rcCpy[row][col]) {
            rcCpy[row][col] = 0;
          } else {
            rcCpy[row][col] = 1;
          }
        }
      }
    }

    int total = 0;
    for (int col = 0; col < c; ++col) {
      int flipped = 0;
      for (int row = 0; row < r; ++row) {
        if (rcCpy[row][col] == 0) ++flipped;
      }
      if (flipped > r / 2) total += flipped;
      else total += (r - flipped);
    }
    ans = max(ans, total);
  }
  cout << ans << endl;
  return 0;
}