#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

constexpr int INF = INT32_MAX / 2;

vector<int> compress(vector<int> vs) {
  vector<int> uniques = vs;

  sort(uniques.begin(), uniques.end());
  uniques.erase(unique(uniques.begin(), uniques.end()), uniques.end());

  for (auto &v: vs) {
    v = lower_bound(uniques.begin(), uniques.end(), v) - uniques.begin();
  }

  return vs;
}

int main() {
  int n;
  cin >> n;

  vector<int> as(n);
  for (auto &a: as) {
    cin >> a;
  }

  int a_min = *min_element(as.begin(), as.end());

  vector<int> distinations = compress(as);

  vector<bool> used(n, false);

  int ans = 0;

  for (int i = 0; i < n; i++) {
    if (used[i]) continue;

    int cycle_min = INF;
    int cycle_sum = 0;
    int cycle_size = 0;

    int v = i;
    while (!used[v]) {
      cycle_min = min(cycle_min, as[v]);
      cycle_sum += as[v];
      cycle_size++;

      used[v] = true;
      v = distinations[v];
    }

    int cost1 = cycle_sum + (cycle_size - 2) * cycle_min;
    int cost2 = cycle_sum + (cycle_size + 1) * a_min + cycle_min;
    ans += min(cost1, cost2);
  }

  cout << ans << endl;
}