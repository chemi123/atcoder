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

using namespace std;
using ll = long long;

// https://www.ioi-jp.org/joi/2008/2009-ho-prob_and_sol/2009-ho.pdf#page=4

int findLower(const vector<int>& shops, int dest) {
  int ok = -1;
  int ng = (int)shops.size();
  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    if (shops[mid] == dest) return dest;
    else if (shops[mid] > dest) ng = mid;
    else ok = mid;
  }
  return shops[ok];
}

int findLarger(const vector<int>& shops, int dest) {
  int ok = (int)shops.size();
  int ng = -1;
  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    if (shops[mid] == dest) return dest;
    else if (shops[mid] > dest) ok = mid;
    else ng = mid;
  }
  return shops[ok];
}

int main() {
  int d, n, m;
  cin >> d >> n >> m;
  vector<int> shops;
  shops.emplace_back(0);
  shops.emplace_back(d);
  rep (i, n-1) {
    int x;
    cin >> x;
    shops.emplace_back(x);
  }
  sort(shops.begin(), shops.end());

  vector<int> dests(m);
  rep (i, m) cin >> dests[i];

  int ans = 0;
  rep (i, m) {
    int l = findLower(shops, dests[i]);
    int r = findLarger(shops, dests[i]);
    ans += min(abs(l - dests[i]), abs(r - dests[i]));
  }
  cout << ans << endl;

  return 0;
}