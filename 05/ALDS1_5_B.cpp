#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using LP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;

template <typename T>
ll merge(vector<T>& a,int l,int r){
  int m=(l+r)/2;
  int n1=abs(l-m);
  int n2=abs(r-m);
  vector<T> lv(n1+1),rv(n2+1);

  for(int i=0;i<n1;i++) lv[i]=a[l+i];
  for(int i=0;i<n2;i++) rv[i]=a[m+i];
  const T inf=numeric_limits<T>::max();
  lv[n1]=inf;
  rv[n2]=inf;

  ll res=0;
  int i=0,j=0;
  for(int k=l;k<r;k++){
    res++;
    if(lv[i]<=rv[j]){
      a[k]=lv[i];
      i++;
    }else{
      a[k]=rv[j];
      j++;
    }
  }
  return res;
}

template <typename T>
ll mergeSort(vector<T>& a,int l,int r){
  if(l+1==r) return 0;
  int m=(l+r)/2;
  ll res=0;
  res+=mergeSort<T>(a,l,m);
  res+=mergeSort<T>(a,m,r);
  res+=merge<T>(a,l,r);
  return res;
}

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  range(i,0,n){
    cin>>a[i];
  }
  ll ans=mergeSort<int>(a,0,n);
  cout<<a<<endl<<ans<<endl;
}