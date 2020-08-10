#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<string> candidates;
  for (int i = 0; i < 10; ++i) {
    string candidate(to_string(i));
    for (int j = 0; j < 10; ++j) {
      if (candidate.size() == 1) {
        candidate += to_string(j);
      } else {
        candidate = candidate[0] + to_string(j);
      }
      for (int k = 0; k < 10; ++k) {
        candidates.emplace_back(candidate + to_string(k));
      }
    }
  }

  int res = 0;
  for (const auto& candidate : candidates) {
    int index = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (candidate[index] == s[i]) {
        ++index;
        if (index == 3) {
          ++res;
          break;
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}