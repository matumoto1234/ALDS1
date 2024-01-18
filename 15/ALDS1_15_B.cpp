#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, w;
  cin >> n >> w;

  vector<pair<int, int>> vws(n);
  for (int i = 0; i < n; i++) {
    auto &[v, w] = vws[i];
    cin >> v >> w;
  }

  sort(vws.begin(), vws.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
    auto [av, aw] = a;
    auto [bv, bw] = b;

    return (double)(av) / (double)(aw) > (double)(bv) / (double)(bw);
  });

  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    auto [vi, wi] = vws[i];

    if (w < wi) {
      sum += (double)(vi) * (double)(w) / (double)(wi);
      w = 0;
      break;
    } else {
      sum += vi;
      w -= wi;
    }
  }

  cout << fixed << setprecision(10);
  cout << sum << endl;
}