#include<iostream>
#include<vector>
using namespace std;
const int MAXN=100;
const int INF=100100100;

int n;
vector<vector<int>> g(MAXN);
int d[MAXN],f[MAXN];
void dfs(int idx,int& cnt){
  if(d[idx]!=INF){
    return;
  }
  d[idx]=cnt;
  cnt++;
  for(int e : g[idx]){
    dfs(e,cnt);
  }
  f[idx]=cnt;
  cnt++;
}

void init(){
  for(int i=0;i<MAXN;i++){
    d[i]=f[i]=INF;
  }
}

int main(){
  init();
  cin>>n;

  for(int i=0;i<n;i++){
    int u,k;
    cin>>u>>k;
    u--;
    for(int j=0;j<k;j++){
      int v;
      cin>>v;
      v--;
      g[u].push_back(v);
    }
  }
  int cnt=1;
  for(int i=0;i<n;i++){
    dfs(i, cnt);
  }
  for(int i=0;i<n;i++){
    cout<<i+1<<' '<<d[i]<<' '<<f[i]<<endl;
  }
  return 0;
}