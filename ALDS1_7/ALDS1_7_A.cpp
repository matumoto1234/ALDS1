#include<bits/stdc++.h>
using namespace std;

struct Node{
  int p;
  int depth;
  vector<int> Childlen;
};

// Tをグローバル変数にしても良い
// vector<Node>& TはC言語でいうところのアドレス渡し
// これでvectorを渡してる
void getDepth(int index,int depth,vector<Node>& T){
  T[index].depth=depth;

  int sz=T[index].Childlen.size();
  // 子がないなら終了
  if(sz==0){
    return;
  }

  for(int j=0;j<sz;j++){
    // 子に向かうので深さを+1
    int to=T[index].Childlen[j];
    getDepth(to,depth+1,T);
  }

  return;
}

// Tをグローバル変数にしても良い
// vector<Node>& Tは長い
// T[i].Childlen[j]を出力する
void outputChildlen(int index,vector<Node>& T){
  int sz=T[index].Childlen.size();
  for(int j=0;j<sz;j++){
    // 最初以外は", "を出力する
    if(j>=1){
      cout<<", ";
    }
    cout<<T[index].Childlen[j];
  }
}

// Tをグローバル変数にしても良い
// vector<Node>& Tは長い
// 親がないなら根,子がないなら葉,それ以外は節
string name(int index,vector<Node>& T){
  if(T[index].p==-1) return "root";
  else if(T[index].Childlen.size()==0) return "leaf";
  else return "internal node";
}

int main(){
  int n;
  cin>>n;

  // Graph
  vector<vector<int>> G(n);
  for(int i=0;i<n;i++){
    int id,k;
    cin>>id>>k;
    for(int j=0;j<k;j++){
      int child;
      cin>>child;
      G[id].push_back(child);
    }
  }

  // Treeの初期化
  vector<Node> T(n);
  for(int i=0;i<n;i++){
    T[i].p=-1;
  }

  // 親を決める
  for(int i=0;i<n;i++){
    // 伸びてる辺の数だけループする
    int sz=G[i].size();
    for(int j=0;j<sz;j++){
      int child=G[i][j];
      T[child].p=i;
      T[i].Childlen.push_back(child);
    }
  }

  // 根を決める
  int root;
  for(int i=0;i<n;i++){
    if(T[i].p==-1) root=i;
  }

  // rootから深さを0で始めていく
  getDepth(root,0,T);

  // 出力
  for(int i=0;i<n;i++){
    cout<<"node "<<i;
    cout<<": parent = "<<T[i].p;
    // 根から目的地までの深さ
    cout<<", depth = "<<T[i].depth;
    // 名前を出力
    cout<<", "<<name(i,T);
    cout<<", [";
    // 子の出力
    outputChildlen(i,T);
    cout<<"]\n";
  }
  return 0;
}