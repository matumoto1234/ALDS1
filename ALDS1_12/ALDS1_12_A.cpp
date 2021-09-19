#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

struct edge{
  ll cost;
  int u,v;

  edge(){}
  edge(ll cost,int u,int v):cost(cost),u(u),v(v){}
  friend bool operator<(const edge& a,const edge& b) {
    return a.cost<b.cost;
  }
};

template <typename T> struct UnionFind{
  vector<T> par;
  vector<T> siz;

  UnionFind(int _siz):par(_siz),siz(_siz){
    for(int i=0;i<_siz;i++){
      par[i]=i;
      siz[i]=1;
    }
  }

  bool merge(int x,int y){
    int rx=root(x),ry=root(y);
    if(rx==ry) return false;

    if(siz[rx]<siz[ry]){
      swap(rx,ry);
    }
    siz[rx]+=siz[ry];
    par[ry]=rx;
    return true;
  }

  T root(int x){
    if(par[x]==x){
      return x;
    }
    return par[x]=root(par[x]);
  }

  bool isSame(int x,int y){
    return root(x)==root(y);
  }

  T size(int x){
    return siz[x];
  }
};

int main(){
  int n;
  cin>>n;

  vector<edge> E;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int k;
      cin>>k;
      if(k==-1) continue;
      if(j>i) continue;
      E.emplace_back(k,i,j);
    }
  }
  sort(E.begin(),E.end());

  UnionFind<ll> t(n);
  ll ans=0;
  int len=(int)E.size();

  for(int i=0;i<len;i++){
    if(t.isSame(E[i].u,E[i].v)) continue;
    t.merge(E[i].u,E[i].v);
    ans+=E[i].cost;
  }
  cout<<ans<<endl;
  return 0;
}