#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
const int INF = 100100100;

// 1-indexed
int N,now;
vector<int> A;

void output(){
  for(int i=1;i<=N;i++){
    if(i>1) cout<<' ';
    cout<<A[i];
  }
  cout<<endl;
}

void bubbleswap(int i){
  if(i==1){
    return;
  }
  int p=i/2;
  swap(A[i],A[p]);
  bubbleswap(p);
}

void build(){
  now=1;

  while(now<N){
    bubbleswap(now);
    now++;
    swap(A[1],A[now]);
  }
}

int main(){
  cin>>N;
  A.assign(N+1,-INF);
  for(int i=1;i<=N;i++){
    cin>>A[i];
  }

  sort(A.begin(),A.end());
  build();
  output();
}