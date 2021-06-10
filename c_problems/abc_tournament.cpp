#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
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

// https://atcoder.jp/contests/abc188/tasks/abc188_c

int main() {
  int n; cin >> n;
  vector<pi> players(1 << n);
  rep (i, 1 << n) {
    int rate; cin >> rate;
    players[i] = pi(i + 1, rate);
  }
  while (players.size() > 2) {
    vector<pi> tmp;
    rep (i, players.size() / 2) {
      if (players[i*2].second > players[i*2+1].second) tmp.emplace_back(players[i*2]);
      else tmp.emplace_back(players[i*2+1]);
    }
    players = tmp;
  }
  if (players[0].second < players[1].second) cout << players[0].first << endl;
  else cout << players[1].first << endl;
  return 0;
}
