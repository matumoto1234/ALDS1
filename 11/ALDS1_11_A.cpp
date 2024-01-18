#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;
  cin>>n;
  int G[100][100]={};
  for(int i=0;i<n;i++){
    int u,k;
    cin>>u>>k;
    u--;
    for(int j=0;j<k;j++){
      int v;
      cin>>v;
      v--;
      G[u][v]=1;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(j) cout<<' ';
      cout<<G[i][j];
    }
    cout<<'\n';
  }
  return 0;
}