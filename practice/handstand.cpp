#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define reps(i, s, n) for (int i = s; i < n; i++)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1000000007;

// https://atcoder.jp/contests/abc124/tasks/abc124_d

int main() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  vector<int> block;
  if (s[0] == '0') block.emplace_back(0);
  for (int left = 0; left < (int)s.size();) {
    char letter = s[left];
    int right = left;
    while (right + 1 < (int)s.size() && s[right+1] == letter) ++right;
    block.emplace_back(right - left + 1);
    left = right + 1;
  }
  if (s.back() == '0') block.emplace_back(0);
  vector<int> acc((int)block.size());
  acc[0] = block[0];
  reps (i, 1, (int)acc.size()) acc[i] = acc[i-1] + block[i];

  int ans = 0;
  for (int left = 0; left < (int)block.size(); left += 2) {
    int right = min((int)block.size() - 1, left + 2 * k);
    int tmp = acc[right];
    if (left > 0) tmp -= acc[left-1];
    ans = max(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}