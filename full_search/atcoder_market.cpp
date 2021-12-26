#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> items(2 * n);
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    items[2 * i] = a[i];
    items[2 * i + 1] = b[i];
  }
  uint64_t ans = 10e18;
  for (int i = 0; i < 2 * n; ++i) {
    for (int j = 0; j < 2 * n; ++j) {
      int in = items[i];
      int out = items[j];
      uint64_t total = 0;
      for (int k = 0; k < n; ++k) {
        total += (uint64_t)abs(a[k] - in);
        total += (uint64_t)abs(a[k] - b[k]);
        total += (uint64_t)abs(b[k] - out);
      }
      ans = min(ans, total);
    }
  }
  cout << ans << endl;
  return 0;
}