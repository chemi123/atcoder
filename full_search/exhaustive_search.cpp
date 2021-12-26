#include <iostream>
#include <vector>

using namespace std;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=ja

// dfsによる全探索でも良いが、bit探索の練習なので今回は使わない
bool search(const vector<int>& a, int m, int index, int sum) {
  if (sum == m) return true;
  if (index == (int)a.size()) return false;

  bool res = search(a, m, index + 1, sum + a[index]);
  res |= search(a, m, index + 1, sum);
  return res;
}

bool bitSearch(const vector<int>& a, int m) {
  int n = (int)a.size();
  for (int bit = 0; bit < (1 << n); ++bit) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) {
        sum += a[i];
      }
    }
    if (sum == m) return true;
  }
  return false;
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
    if (bitSearch(a, m)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}