#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
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

// https://atcoder.jp/contests/abc114/tasks/abc114_c

void rec(vector<int>& ump, const vector<int>& nums, ll num, int nextNum, int& ans, int n) {
  num *= 10;
  num += (ll)nextNum;
  if (num > (ll)n) return;
  if (ump[3] > 0 && ump[5] > 0 && ump[7] > 0) ++ans;
  for (auto e : nums) {
    ++ump[e];
    rec(ump, nums, num, e, ans, n);
    --ump[e];
  } 
}

int main() {
  int n; cin >> n;
  int ans = 0;
  vector<int> nums{3, 5, 7};
  vector<int> ump(10);
  for (auto nextNum : nums) {
    ++ump[nextNum];
    rec(ump, nums, 0LL, nextNum, ans, n);
    --ump[nextNum];
  }
  cout << ans << endl;
  return 0;
}