#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
using ll = long long;
using lP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF = INT64_MAX / 2LL;
const int inf = INT32_MAX / 2;

bool isPrime(int x){
  if(x==1) return false;
  for(int i=2;i*i<=x;i++){
    if(x%i==0) return false;
  }
  return true;
}

int main() {
  int n;
  cin>>n;
  int ans=0;
  range(i,0,n){
    int x;
    cin>>x;
    if(isPrime(x)) ans++;
  }
  cout<<ans<<endl;
}