#include<iostream>
#include<vector>
#include<limits>
#include<queue>
using namespace std;
using ll = long long;

template <typename T> struct Dijkstra{
  struct edge{
    int to;
    T cost;

    edge(){}
    edge(int to,T cost):to(to),cost(cost){}
    bool operator<(const edge& e) const {return cost>e.cost;}
  };

  T inf(){return numeric_limits<T>::max();}

  vector<vector<edge>> G;
  vector<T> ds;
  Dijkstra(int n):G(n),ds(n){}

  void add_edge(int from,int to,T cost){G[from].emplace_back(to,cost);}

  void build(int start){
    int n=G.size();
    ds.assign(n,inf());
    priority_queue<edge> Q;
    ds[start]=0;
    Q.emplace(start,ds[start]);
    while(!Q.empty()){
      edge p=Q.top();
      Q.pop();
      int v=p.to;
      if(ds[v]<p.cost) continue;
      for(edge e:G[v]){
        if(ds[e.to]>ds[v]+e.cost){
          ds[e.to]=ds[v]+e.cost;
          Q.emplace(e.to,ds[e.to]);
        }
      }
    }
  }

  T operator[](int k){return ds[k];}
};

int main(){
  int n;
  cin>>n;
  Dijkstra<ll> G(n);
  for(int i=0;i<n;i++){
    int u,k;
    cin>>u>>k;
    for(int j=0;j<k;j++){
      int v;
      ll c;
      cin>>v>>c;
      G.add_edge(u,v,c);
    }
  }
  G.build(0);
  for(int i=0;i<n;i++){
    cout<<i<<' '<<G[i]<<'\n';
  }
  return 0;
}