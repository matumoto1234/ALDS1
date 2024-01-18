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

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  range(i,0,n){
    cin>>a[i];
  }
  set<int> s;
  range(i,0,1<<n){
    int sum=0;
    range(j,0,n){
      if(i>>j&1){
        sum+=a[j];
      }
    }
    s.insert(sum);
  }
  int q;
  cin>>q;
  range(i,0,q){
    int x;
    cin>>x;
    cout<<(s.find(x)!=s.end()?"yes":"no")<<endl;
  }
}