#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  uint64_t k;
  cin >> k;
  if (k % 2 == 0) {
    cout << "-1" << endl;
    return 0;
  }

  int res = 1;
  int formula = 7;
  unordered_set<int> s;
  while (1) {
    int mod = formula % k;
    if (mod == 0) {
      cout << res << endl;
      break;
    }
    if (s.find(mod) != s.end()) {
      cout << "-1" << endl;
      break;
    }
    ++res;
    s.insert(mod);
    formula = mod * 10 + 7;
  }

  return 0;
}