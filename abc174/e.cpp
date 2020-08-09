#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// https://atcoder.jp/contests/arc032/tasks/arc032_2

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> logs;
  int ng = 0, ok = 1e9;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    logs.emplace_back(a);
  }
  while (ok - ng > 1) {
    int mid = (ng + ok) / 2;
    int tryNum = 0;
    for (const auto& log : logs) {
      tryNum += (log - 1) / mid;
      if (tryNum > k) {
        break;
      }
    }
    if (tryNum <= k) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << ok << endl;
  return 0;
}