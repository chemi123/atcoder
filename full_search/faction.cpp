#include <iostream>
#include <vector>
#include <bitset>

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
    int t = bitset<32>(bit).count();
    if (t <= ans) continue;

    vector<int> set;
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) set.emplace_back(i+1);
    }

    bool ok = true;
    for (int i = 0; i < set.size(); ++i) {
      for (int j = i + 1; j < set.size(); ++j) {
        if (!combi[set[i]][set[j]]) {
          ok = false;
          break;
        }
      }
      if (!ok) break;
    }
    if (ok) ans = t;
  }
  cout << ans << endl;
  return 0;
}