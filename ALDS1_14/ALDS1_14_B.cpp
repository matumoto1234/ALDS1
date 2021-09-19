#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ull = unsigned long long;
using ll = long long;
using Pll = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

template<typename T,T MOD,T B>
struct RollingHash{
  vector<T> hash,accum_hash;
  vector<T> inv;
  RollingHash(vector<T> vals){build(vals);}
  RollingHash(string &s){
    vector<T> vals;
    for(char c:s) vals.emplace_back(c);
    build(vals);
  }

  T pow(T a,T e){
    if(e==0) return 1;
    if(e%2==0){
      T res=pow(a,e/2);
      return (res*res)%MOD;
    }
    return (pow(a,e-1)*a)%MOD;
  }

  void build(vector<T> vals){
    int n=vals.size();
    hash.assign(n,0);
    accum_hash.assign(n+1,0);
    inv.assign(n+1,0);
    inv[n]=pow(B,n*(MOD-2));
    for(int i=n-1;i>=0;i--) inv[i]=(inv[i+1]*B)%MOD;
    for(int i=0;i<n;i++) hash[i]=(vals[i]*pow(B,i))%MOD;
    for(int i=0;i<n;i++) accum_hash[i+1]=(hash[i]+accum_hash[i])%MOD;
  }

  // [l,r)
  T find(int l,int r){
    T res=accum_hash[r]-accum_hash[l];
    if(res<0) res+=MOD;
    res=(res*inv[l])%MOD;
    return res;
  }
};

int main() {
  string s,t;
  cin>>s>>t;

  const ll M=1e9+7LL;
  const ll B=1e8+7LL;
  
  RollingHash<ll,M,B> a(s);
  RollingHash<ll,M,B> b(t);

  int n=s.size(),m=t.size();
  range(i,0,n-m+1){
    if(a.find(i,i+m)==b.find(0,m)){
      cout<<i<<newl;
    }
  }
}