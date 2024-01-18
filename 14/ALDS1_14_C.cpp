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

template <typename T,T MOD,T B1,T B2>
struct RollingHash2D{
  struct CumlativeSum2D{
    vector<vector<T>> data;
    CumlativeSum2D(){}
    CumlativeSum2D(int H,int W):data(H+1,vector<T>(W+1,0)){}

    void set(int y,int x,T v){ data[y+1][x+1]+=v; }

    void build(){
      for(int i=1;i<(int)data.size();i++){
        for(int j=1;j<(int)data[i].size();j++){
          data[i][j]+=(data[i][j-1]+data[i-1][j]-data[i-1][j-1])%MOD;
          if(data[i][j]<0) data[i][j]+=MOD;
        }
      }
    }

    // [ (sy,sx), (gy,gx) )
    T query(int sy,int sx,int gy,int gx){
      T res=(data[gy][gx]-data[gy][sx]-data[sy][gx]+data[sy][sx])%MOD;
      if(res<0) res+=MOD;
      return res;
    }
  };

  CumlativeSum2D cumlative_sum;
  vector<vector<T>> inv;
  RollingHash2D(vector<vector<T>> vals){ build(vals); }
  RollingHash2D(vector<string> &s){
    vector<vector<T>> vals(s.size());
    for(int i=0;i<(int)s.size();i++){
      for(int j=0;j<(int)s[0].size();j++){
        T val=s[i][j]%MOD;
        if(val<0) val+=MOD;
        vals[i].emplace_back(val);
      }
    }
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

  void build(vector<vector<T>> vals){
    int h=vals.size(),w=vals[0].size();
    inv.assign(h+1,vector<T>(w+1,0));
    cumlative_sum.data.assign(h+1,vector<T>(w+1,0));
    inv[h][w]=(pow(B1,h*(MOD-2))*pow(B2,w*(MOD-2)))%MOD;
    for(int i=h-1;i>=0;i--) inv[i][w]=(inv[i+1][w]*B1)%MOD;
    for(int j=w-1;j>=0;j--) inv[h][j]=(inv[h][j+1]*B2)%MOD;
    for(int i=h-1;i>=0;i--) for(int j=w-1;j>=0;j--){
      inv[i][j]=(((inv[i+1][j+1]*B1)%MOD)*B2)%MOD;
    }
    for(int i=0;i<h;i++) for(int j=0;j<w;j++){
      T val=(((vals[i][j]*pow(B1,i))%MOD)*pow(B2,j))%MOD;
      cumlative_sum.set(i,j,val);
    }
    cumlative_sum.build();
  }

  T find(int sy,int sx,int gy,int gx){
    return (cumlative_sum.query(sy,sx,gy,gx)*inv[sy][sx])%MOD;
  }
};

int main() {
  int h1,w1;
  cin>>h1>>w1;
  vector<string> s(h1);
  range(i,0,h1) cin>>s[i];

  int h2,w2;
  cin>>h2>>w2;
  vector<string> t(h2);
  range(i,0,h2) cin>>t[i];

  const ll M=(ll)1e9+7;
  const ll B1=(ll)1e8+7;
  const ll B2=(ll)1e7+7;

  RollingHash2D<ll,M,B1,B2> S(s);
  RollingHash2D<ll,M,B1,B2> T(t);

  range(i,0,h1-h2+1) range(j,0,w1-w2+1){
    if(S.find(i,j,i+h2,j+w2)==T.find(0,0,h2,w2)){
      cout<<i<<' '<<j<<newl;
    }
  }
}