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

bool isValidLine(const string& line, int w) {
  if (w == 1) return true;
  rep (i, w - 1) {
    if (i == 0) {
      if (line[i] == 'o' && line[i+1] == 'o') return false;
    } else {
      if ((line[i-1] == 'o' && line[i] == 'o') || (line[i] == 'o' && line[i+1] == 'o')) return false;
    }
  }
  return true;
}

bool isValidLines(const string& prevLine, const string& currentLine, int w) {
  if (w == 1) return !(prevLine == "o" && currentLine == "o");
  rep (col, w) {
    if (prevLine[col] != 'o') continue;
    if (prevLine[col] == 'o' && currentLine[col] == 'o') return false;
    if (col == 0) {
      if (prevLine[col] == 'o' && currentLine[col+1] == 'o') return false;
    } else if (col == w - 1) {
      if (prevLine[col] == 'o' && currentLine[col-1] == 'o') return false;
    } else {
      if (prevLine[col] == 'o' && currentLine[col+1] == 'o') return false;
      if (prevLine[col] == 'o' && currentLine[col-1] == 'o') return false;
    }
  }
  return true;
}

int main() {
  int h, w; cin >> h >> w;
  vector<string> grid(h);
  rep (i, h) cin >> grid[i];

  vector<ll> dp(1 << w, 1);

  set<string> s;
  rep (bit, 1 << w) {
    string line = grid[0];
    rep (i, w) if ((bit >> i & 1) && line[i] == '.') line[i] = 'o';
    if (s.find(line) != s.end()) {
      dp[bit] = -1;
      continue;
    }
    s.emplace(line);
    if (!isValidLine(line, w)) dp[bit] = -1;
  }

  reps (row, 1, h) {
    s.clear();
    vector<ll> tmp(1 << w, 0);
    rep (bit, 1 << w) {
      string line = grid[row];
      rep (i, w) if ((bit >> i & 1) && line[i] == '.') line[i] = 'o';
      if (s.find(line) != s.end()) {
        tmp[bit] = -1;
        continue;
      }
      s.emplace(line);
      if (!isValidLine(line, w)) {
        tmp[bit] = -1;
        continue;
      }

      rep (bit2, 1 << w) {
        if (dp[bit2] == -1) continue;
        string prevLine = grid[row-1];
        rep (i, w) if ((bit2 >> i & 1) && prevLine[i] == '.') prevLine[i] = 'o';
        if (isValidLines(prevLine, line, w)) tmp[bit] = (tmp[bit] + dp[bit2]) % MOD;
      }
    }
    tmp.swap(dp);
  }
  ll ans = 0;
  rep (i, 1 << w) if (dp[i] != -1) ans = (ans + dp[i]) % MOD;
  cout << ans << endl;
  return 0;
}