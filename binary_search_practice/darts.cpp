#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define debug(s, param) std::cerr << s << param << std::endl;
#define output(ans) std::cout << ans << std::endl;

using namespace std;
using ll = long long;

// https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c

int binarySearch(const vector<int>& nums, int target) {
  int ok = -1;
  int ng = nums.size();
  while(abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    if (nums[mid] == target) return nums[mid];
    else if (nums[mid] < target) ok = mid;
    else ng = mid;
  }
  if (ok == -1) return 0;
  return nums[ok];
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> nums(n, 0);
  rep (i, n) cin >> nums[i];

  rep (i, n) {
    rep (j, n) {
      int sum = nums[i] + nums[j];
      if (sum == m) {
        cout << m << endl;
        return 0;
      }
      if (sum < m) nums.emplace_back(sum);
    }
  }
  nums.emplace_back(0);
  sort(nums.begin(), nums.end());

  int ans = 0;
  n = (int)nums.size();
  rep (i, n) {
    int rest = m - nums[i];
    ans = max(ans, nums[i] + binarySearch(nums, rest));
  }
  output(ans);
  return 0;
}