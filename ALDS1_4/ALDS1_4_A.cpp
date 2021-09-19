#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> S(n);
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  int q;
  int ans = 0;
  cin >> q;
  vector<int> T(q);
  for (int i = 0; i < q; i++) {
    cin >> T[i];
    for (int j = 0; j < n; j++) {
      if (T[i] == S[j]) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}