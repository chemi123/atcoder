#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

/*
  問題: https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c

  考え方
  ４回まで投げられるが、例えば２回しか投げない場合はのは4回投げたが2回は0点を取ったとして考える。
  その上で全探索を行うとO(n^4)となり到底間に合わない。
  なので2回投げた場合の得点を列挙し、その集合をSとする。これに必要な計算量(及び空間量)はO(n^2)となる。
  そしてSを昇順ソートする。これは計算量はN^2logN^2=2N^2logN、つまりO(N^2logN)となる。
  最後にソートされたSをイテレートし、それぞれの要素をsとした場合は残りの得点はM-sとなる。
  Sから二分探索でM-s以下の最大の要素を探せば良い。これはO(N^2logN)の計算量で済む。
  制約は0<=N<=1000であるため、十分間に合う。
*/

const ll MOD = 1000000007;

int binarySearch(vector<int>& S, int target) {
  int ok = 0, ng = (int)S.size();
  while (abs(ok-ng) > 1) {
    int mid = (ok + ng) / 2;
    if (S[mid] == target) {
      return mid;
    } else if (S[mid] < target) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> points(n+1, 0);
  for (int i = 1; i <= n; ++i) cin >> points[i];
  vector<int> S;
  S.reserve((n+1) * (n+1));
  for (int i = 0; i <= n; ++i) for (int j = i; j <= n; ++j) S.emplace_back(points[i]+points[j]);
  sort(S.begin(), S.end());
  int ans = 0;
  for (auto s : S) {
    if (s > m) break;
    int sum = s + S[binarySearch(S, m - s)];
    if (sum == m) {
      ans = sum;
      break;
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
