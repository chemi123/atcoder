#include <iostream>

using namespace std;

// https://atcoder.jp/contests/abc122/tasks/abc122_b

int main() {
  string s;
  cin >> s;
  int res = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] != 'A' && s[i] != 'C' && s[i] != 'G' && s[i] != 'T') continue;
    res = max(res, 1);
    for (int j = i + 1; j < (int)s.size(); ++j) {
      if (s[j] != 'A' && s[j] != 'C' && s[j] != 'G' && s[j] != 'T') break;
      res = max(res, j - i + 1);
    }
  }
  cout << res << endl;
  return 0;
}