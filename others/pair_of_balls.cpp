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

// https://atcoder.jp/contests/abc216/tasks/abc216_d

void recursive_pop(vector<queue<int>>& tube, vector<queue<int>>& tops, int ballNumber) {
  while (!tops[ballNumber].empty()) {
    int nextTube = tops[ballNumber].front(); tops[ballNumber].pop();
    if (!tube[nextTube].empty()) {
      int nextBall = tube[nextTube].front(); tube[nextTube].pop();
      tops[nextBall].emplace(nextTube);
      if (tops[nextBall].size() == 2) recursive_pop(tube, tops, nextBall);
    }
  }
}

int main() {
  int n, m; cin >> n >> m;
  vector<queue<int>> tube(m), tops(n);
  rep (i, m) {
    int k; cin >> k;
    rep (j, k) {
      int a; cin >> a; --a;
      if (j == 0) tops[a].emplace(i);
      else tube[i].emplace(a);
    }
  }

  rep (i, n) if (tops[i].size() == 2) recursive_pop(tube, tops, i);
  bool ok = true;
  rep (i, m) if (!tube[i].empty()) ok = false;
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}