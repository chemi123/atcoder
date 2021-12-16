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

// https://atcoder.jp/contests/digitalarts2012/tasks/digitalarts_1

int main() {
  vector<string> s;
  int n;
  while (1) {
    string str; cin >> str;
    if ('0' <= str[0] && str[0] <= '9') {
      n = stoi(str);
      break;
    }
    s.emplace_back(str);
  }
  vector<string> ngs(n);
  rep (i, n) cin >> ngs[i];
  vector<string> ans;
  for (auto word : s) {
    bool ok = true;
    for (auto ng : ngs) {
      if (word.size() != ng.size()) continue;
      bool match = true;
      rep (i, word.size()) {
        if (!(word[i] == ng[i] || ng[i] == '*')) match = false;
      }
      if (match) ok = false;
    }
    if (ok) ans.emplace_back(word);
    else {
      string tmp(word.size(), '*');
      ans.emplace_back(tmp);
    }
  }
  for (auto e : ans) cout << e << " "; cout << endl;
  return 0;
}