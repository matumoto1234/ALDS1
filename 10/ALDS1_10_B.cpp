#include <bits/stdc++.h>
using namespace std;
const int INF = 100100100;
const int MAXN = 100;

// 行数と列数
vector<int> R(MAXN + 1);
vector<int> C(MAXN);

// dp[l][r]:=[l,r)でのスカラー乗算の回数の最小値
// 最終的な答えは[0,n)のスカラー乗算の回数の最小値
// 小さな区間に分けて計算する
// [0,1),[1,2),[2,3),[3,4),...,[n-1,n)を計算したあとに
// [0,2),[2,4),...,[n-2,n)という風に範囲を狭めていく
vector<vector<int>> dp(MAXN + 1, vector<int>(MAXN + 1, INF));
int solve(int l, int r) {
  if (l == r - 1) { return 0; }

  // 参照渡しにしてresを変更するとdp[l][r]も変わってくれる
  // これの嬉しい点はreturn res;としてreturnで返すものをresに統一できる点。
  int &res = dp[l][r];
  if (res != INF) { return res; }

  // R1行C1列とR2行C2列の行列積のスカラー乗算の回数はR1*C1*C2
  // 行列積を行うにはC1とR2は等しくなくてはならない。
  // ただ、入力はすべてその条件に当てはまったものしか与えられない。
  // だから、C1をR2として計算して良い
  // lからm-1までの行列積を計算した時、計算結果の行列はdp[l]C[m-1]となる。
  // mからr-1までの行列積を計算した時、計算結果の行列はdp[m]C[r-1]となる。
  // スカラー乗算の回数はR[l]*C[m-1]*C[r-1]で、これをRにすると
  // R[l]*R[m]*R[r]を計算すれば良い。
  // mは[l,m),[m,r)となるような半開区間
  for (int m = l + 1; m <= r; m++) {
    int v = solve(l, m) + solve(m, r) + R[l] * R[m] * R[r];
    res = min(res, v);
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> R[i] >> C[i];
  }
  R[n] = C[n - 1];
  cout << solve(0, n) << endl;
  return 0;
}