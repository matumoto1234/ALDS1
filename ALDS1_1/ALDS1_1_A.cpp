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


struct insertionSort{
  vector<int> a;
  insertionSort(){}
  insertionSort(vector<int> v):a(v){}
  
  void build_output(){
    range(i,1,a.size()){
      int v=a[i];
      int j=i-1;
      while(j>=0&&a[j]>v){
        a[j+1]=a[j];
        j--;
      }
      a[j+1]=v;
      output();
    }
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
  insertionSort b(a);
  b.output();
  b.build_output();
}