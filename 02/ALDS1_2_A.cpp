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

struct bubbleSort{
  vector<int> a;
  bubbleSort(const vector<int>& v):a(v){}

  int build_count(){
    int res=0;
    bool flg=true;
    while(flg){
      flg=false;
      rrange(i,1,a.size()){
        if(a[i]<a[i-1]){
          swap(a[i],a[i-1]);
          flg=true;
          res++;
        }
      }
    }
    return res;
  }

  void output(){
    range(i,0,a.size()){
      if(i) cout<<' ';
      cout<<a[i];
    }
    cout<<endl;
  }
};

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  range(i,0,n){
    cin>>a[i];
  }
  bubbleSort b(a);
  int ans=b.build_count();
  b.output();
  cout<<ans<<endl;
}