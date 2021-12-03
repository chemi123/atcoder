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
#include <tuple>

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

// https://atcoder.jp/contests/abc167/tasks/abc167_d

tuple<int, ll> dfs1(const vector<int>& graph, map<int, int>& visit, ll cnt, int current) {
  if (visit.find(current) != visit.end()) return tuple<int, ll>(current, cnt - visit[current]);
  visit[current] = cnt;
  return dfs1(graph, visit, cnt + 1, graph[current]);
}

tuple<int, ll> dfs2(const vector<int>& graph, ll cnt, ll& k, int p, int current) {
  if (p == current || k == 0) return tuple<int, ll>(current, cnt);
  return dfs2(graph, cnt + 1, --k, p, graph[current]);
}

int dfs3(const vector<int>& graph, int current, ll k) {
  if (k == 0) return current;
  return dfs3(graph, graph[current], k - 1);
}

int main() {
  int n; cin >> n;
  ll k; cin >> k;
  vector<int> graph(n);
  rep (i, n) {
    cin >> graph[i];
    --graph[i];
  }
  map<int, int> visit;
  auto [p1, period] = dfs1(graph, visit, 0, 0);
  ll tmp = k;
  auto [p2, cnt] = dfs2(graph, 0, tmp, p1, 0);
  if  (tmp == 0) {
    cout << p2 + 1 << endl;
    return 0;
  }
  k -= cnt;
  k %= period;
  cout << dfs3(graph, p1, k) + 1 << endl;
  return 0;
}