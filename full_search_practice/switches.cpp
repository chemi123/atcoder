#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// https://atcoder.jp/contests/abc128/tasks/abc128_c

int main() {
  int n, m;
  cin >> n >> m;
  unordered_map<int, vector<int>> mp;
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int s;
      cin >> s;
      mp[i+1].emplace_back(s);
    }
  }
  vector<int> ptn(m);
  for (int i = 0; i < m; ++i) cin >> ptn[i];

  int ans = 0;
  // N個あるスイッチの全on/offをbit全探索
  for (int bit = 0; bit < (1 << n); ++bit) {
    vector<int> bits;
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) {
        bits.emplace_back(i+1);
      }
    }

    int total = 0;
    for (auto& [i, s] : mp) {
      int on = 0;
      for (auto e : bits) {
        if (find(s.begin(), s.end(), e) != s.end()) ++on;
      }
      if (on % 2 == ptn[i-1]) ++total;
    }
    if (total == m) ++ans;
  }

  cout << ans << endl;
  return 0;
}