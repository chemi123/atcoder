#include <iostream>
#include <vector>

using namespace std;

bool search(const vector<int>& a, int m, int index, int sum) {
  if (sum == m) return true;
  if (index == (int)a.size()) return false;

  bool res = search(a, m, index + 1, sum + a[index]);
  res |= search(a, m, index + 1, sum);
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int m;
    cin >> m;
    if (search(a, m, 0, 0)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}