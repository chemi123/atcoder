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

// pairの2要素の合計が大きい順に並べる
struct PairComparere {
  const bool operator() (const pi& left, const pi& right) {
    return left.first + left.second < right.first + right.second;
  }
};

void customPriorityQueueComparer() {
  priority_queue<pi, vector<pi>, PairComparere> pq;
  pq.emplace(pi(2, 5));
  pq.emplace(pi(1, 1));
  pq.emplace(pi(3, 8));
  pq.emplace(pi(3, 1));
  pq.emplace(pi(5, 2));
  pq.emplace(pi(1, 9));
  while (!pq.empty()) {
    auto [f, s] = pq.top();
    pq.pop();
    cout << f << " " << s << endl;
  }
}

void customVectorSort() {
  vector<pi> v;
  v.emplace_back(pi(2, 5));
  v.emplace_back(pi(1, 1));
  v.emplace_back(pi(3, 8));
  v.emplace_back(pi(3, 1));
  v.emplace_back(pi(5, 2));
  v.emplace_back(pi(1, 9));

  auto comparer = [](const pi& left, const pi& right) {
    return left.first + left.second > right.first + right.second;
  };
  sort(v.begin(), v.end(), comparer);
  for (auto& [f, s] : v) cout << f << " " << s << endl;
}

int main() {
  customVectorSort();
  return 0;
}