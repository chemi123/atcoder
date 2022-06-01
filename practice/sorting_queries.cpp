#include <algorithm>
#include <bitset>
#include <cassert>
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

// https://atcoder.jp/contests/abc217/tasks/abc217_e
int main() {
  int q; cin >> q;
  queue<int> que;
  priority_queue<int, vector<int>, greater<int>> pq;
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int x; cin >> x;
      que.emplace(x);
    }
    if (type == 2) {
      if (pq.empty()) {
        cout << que.front() << endl;
        que.pop();
      } else {
        cout << pq.top() << endl;
        pq.pop();
      }
    }
    if (type == 3) {
      while (!que.empty()) {
        pq.emplace(que.front());
        que.pop();
      }
    }
  }
  return 0;
}