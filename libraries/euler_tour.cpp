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

// 参考: https://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7
// かなりわかりやすい
void dfs(const vector<vector<int>>& graph, vector<int>& edge, vector<int>& in, vector<int>& out, int& step, int current, int parent) {
  in[current] = step++;
  edge.emplace_back(current);
  for (auto& next : graph[current]) if (next != parent) dfs(graph, edge, in, out, step, next, current);
  out[current] = step++;
  edge.emplace_back(-current);
}

int main() {
  vector<vector<int>> graph(6);
  graph[0].emplace_back(1);
  graph[0].emplace_back(5);
  graph[1].emplace_back(2);
  graph[1].emplace_back(4);
  graph[2].emplace_back(3);
  int step = 0;
  vector<int> in(6), out(6), edge;
  dfs(graph, edge, in, out, step, 0, -1);
  for (auto e : in) cout << e << " "; cout << endl;
  for (auto e : out) cout << e << " "; cout << endl;
  for (auto e : edge) cout << e << " "; cout << endl;
  return 0;
}