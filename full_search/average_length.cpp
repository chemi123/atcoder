#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

// https://atcoder.jp/contests/abc145/tasks/abc145_c

int main() {
  int n;
  cin >> n;
  vector<double> a(n, 0), b(n, 0);
  rep(i, n) cin >> a[i] >> b[i];

  vector<int> indices(n, 0);
  rep(i, n) indices[i] = i;

  double total = 0;
  double patterns = 0;
  do {
    double dist = 0;
    rep (i, (int)indices.size() - 1) {
      dist += sqrt((a[indices[i]] - a[indices[i+1]]) * (a[indices[i]] - a[indices[i+1]]) + (b[indices[i]] - b[indices[i+1]]) * (b[indices[i]] - b[indices[i+1]]));
    }
    ++patterns;
    total += dist;
  } while (next_permutation(indices.begin(), indices.end()));
  stringstream ss;
  cout << fixed << setprecision(9) << total / patterns << endl;

  return 0;
}