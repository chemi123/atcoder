#include <iostream>
#include <vector>

// https://atcoder.jp/contests/abc097/tasks/arc097_b

using namespace std;

int findRoot(int* parent, int x) {
  if (parent[x] == x) {
    return x;
  }
  parent[x] = findRoot(parent, parent[x]);
  return parent[x];
}

bool isSame(int* parent, int x, int y) {
  return findRoot(parent, x) == findRoot(parent, y);
}

void unite(int* parent, int x, int y) {
  x = findRoot(parent, parent[x]);
  parent[x] = findRoot(parent, y);
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> nums;
  nums.reserve(n+1);
  nums.emplace_back(0);
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    nums.emplace_back(num);
  }

  int parent[n+1];
  for (int i = 0; i <= n; ++i) {
    parent[i] = i;
  }

  for (int i = 0; i < m; ++i) {
    int num1, num2;
    cin >> num1 >> num2;
    unite(parent, num1, num2);
  }

  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (isSame(parent, i, nums.at(i))) {
      ++res;
    }
  }
  cout << res << endl;

  return 0;
}