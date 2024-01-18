#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

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
  int n,m;
  cin>>n>>m;
  UnionFind<ll> tree(n);
  for(int i=0;i<m;i++){
    int s,t;
    cin>>s>>t;
    tree.merge(s,t);
  }
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int s,t;
    cin>>s>>t;
    cout<<(tree.isSame(s,t)?"yes":"no")<<'\n';
  }
  return 0;
}