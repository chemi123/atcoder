#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=ja

int main() {
  int n;
  cin >> n;
  vector<int> seqs(n, 0);
  rep (i, n) cin >> seqs[i];
  vector<int> dp(1, seqs[0]);
  for (int i = 1; i < n; ++i) {
    int lastIndex = (int)dp.size() - 1;
    if (dp[lastIndex] < seqs[i]) {
      dp.emplace_back(seqs[i]);
    } else {
      auto it = lower_bound(dp.begin(), dp.end(), seqs[i]);
      *it = seqs[i];
    }
  }
  cout << dp.size() << endl;
  return 0;
}
