#include <iostream>

using namespace std;

int main() { 
  int64_t n, d;
  cin >> n >> d;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int64_t x, y;
    cin >> x >> y;
    if (x * x + y * y <= d * d) {
      ++res;
    }
  }
  cout << res << endl;
  return 0;
}