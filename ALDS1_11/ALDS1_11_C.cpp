#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int INF = 100100100;
const int MAXN = 100;

vector<int> g[MAXN];
vector<int> used(MAXN,-1);
int n;

void bfs(){
  int s=0;
  queue<int> Q;
  Q.push(0);
  used[0]=0;
  while(!Q.empty()){
    int p=Q.front();
    Q.pop();

    for(int e:g[p]){
      if(used[e]!=-1) continue;
      Q.push(e);
      used[e]=used[p]+1;
    }
  }
}

int main(){
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
  bfs();
  for(int i=0;i<n;i++){
    cout<<i+1<<' '<<used[i]<<endl;
  }
  return 0;
}