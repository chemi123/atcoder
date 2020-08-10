#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<uint64_t>> a;
  for (int i = 0; i < n; ++i) {
    vector<uint64_t> vec(m, -1);
    for (int j = 0; j < m; ++j) {
      cin >> vec[j];
    }
    a.emplace_back(vec);
  }

  uint64_t ans = 0;
  for (int i = 0; i < m - 1; ++i) {
    for (int j = i + 1; j < m; ++j) {
      uint64_t scores = 0;
      for (int k = 0; k < n; ++k) {
        scores += max(a[k][i], a[k][j]);
      }
      ans = max(ans, scores);
    }
  }
  cout << ans << endl;
  return 0;
}