#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> logs;
  int l = 0, r = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    r = max(r, a);
    logs.emplace_back(a);
  }
  while (r - l > 1) {
    int mid = (l + r) / 2;
    int tryNum = 0;
    for (const auto& log : logs) {
      tryNum += (log - 1) / mid;
      if (tryNum > k) {
        break;
      }
    }
    if (tryNum > k) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << r << endl;
  return 0;
}