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

// 0-indexed
template <typename T>
struct fenwick_tree{
  vector<T> dat;
  fenwick_tree(int n):dat(n,0){}

  void add(int idx,T v){
    int n=dat.size();
    for(int i=idx;i<n;i|=i+1){
      dat[i]+=v;
    }
  }

  T sum(int idx){
    T res=0;
    for(int i=idx;i>=0;i=(i&(i+1))-1){
      res+=dat[i];
    }
    return res;
  }
};

vector<int> compress(vector<int> a){
  int n=a.size();
  vector<int> res=a;
  sort(a.begin(),a.end());
  map<int,int> mp;
  range(i,0,n){
    mp[a[i]]=i;
  }
  range(i,0,n){
    res[i]=mp[res[i]];
  }
  return res;
}

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  range(i,0,n){
    cin>>a[i];
  }
  a=compress(a);
  ll ans=0;
  fenwick_tree<int> ft(n);
  range(i,0,n){
    ans+=i-ft.sum(a[i]);
    ft.add(a[i],1);
  }
  cout<<ans<<endl;
}
