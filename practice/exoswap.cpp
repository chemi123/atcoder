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

// https://atcoder.jp/contests/arc110/tasks/arc110_c

int main() {
  int n; cin >> n;

  vector<int> p(n);
  unordered_map<int, int> numIndex;
  set<pi> swapped;
  rep (i, n) {
    cin >> p[i];
    --p[i];
    numIndex[p[i]] = i;
  }

  vector<int> ans;
  rep (num, n) {
    auto index = numIndex[num];
    if (num == index) continue;
    while (1) {
      int swapIndex;
      if (num > index) {
        swapIndex = index;
        ++index;
      } else {
        swapIndex = index - 1;
        --index;
      }
      ans.emplace_back(swapIndex + 1);
      if (swapped.find(pi(swapIndex, swapIndex + 1)) != swapped.end()) {
        cout << -1 << endl;
        return 0;
      }
      swapped.emplace(pi(swapIndex, swapIndex + 1));
      
      swap(p[swapIndex], p[swapIndex+1]);
      numIndex[p[swapIndex]] = swapIndex;
      numIndex[p[swapIndex+1]] = swapIndex + 1;
      if (num == numIndex[num]) break;
    }
  }

  bool ok = true;
  rep (i, n - 1) if (swapped.find(pi(i, i + 1)) == swapped.end()) {
    ok = false;
    break;
  }
  if (!ok) cout << -1 << endl;
  else for (auto e : ans) cout << e << endl;
  return 0;
}