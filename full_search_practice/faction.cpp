#include <iostream>
#include <vector>

using namespace std;

// https://atcoder.jp/contests/abc002/tasks/abc002_4

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> combi(13, vector(13, false));
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    combi[x][y] = true;
  }
  int ans = 1;
  // 1からnまでの全ての組み合わせを試してみる
  for (int bit = 0; bit < (1 << n); ++bit) {
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) vec.emplace_back(i+1);
    }
    bool ok = true;
    for (int i = 0; i < (int)vec.size()-1; ++i) {
      for (int j = i + 1; j < (int)vec.size(); ++j) {
        if (!combi[vec[i]][vec[j]]) ok = false;
      }
    }
    if (ok) ans = max(ans, (int)vec.size());
  }
  cout << ans << endl;
  return 0;
}