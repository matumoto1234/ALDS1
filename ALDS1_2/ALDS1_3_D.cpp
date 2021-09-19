#include<bits/stdc++.h>
using namespace std;

void outputV(vector<int> a){
  for(int i=0;i<a.size();i++){
    cout<<a[i]<<endl;
  }
}

int insertionSort(vector<int>& A,int n,int g){
  int cnt=0;
  for(int i=g;i<n;i++){
    int v=A[i];
    int j=i-g;
    while(j>=0&&A[j]>v){
      A[j+g]=A[j];
      j=j-g;
      cnt++;
    }
    A[j+g]=v;
  }
  return cnt;
}

void shellSort(vector<int> A,int n){
  int cnt=0;
  int m=0;
  vector<int> G(1,1);
  while(n>=3*G[m]+1){
    G.push_back(3*G[m]+1);
    m++;
  }
  m++;
  cout<<m<<endl;
  reverse(G.begin(),G.end());
  for(int i=0;i<m;i++){
    if(i){
      cout<<' ';
    }
    cout<<G[i];
    cnt+=insertionSort(A,n,G[i]);
  }
  cout<<endl;
  cout<<cnt<<endl;
  outputV(A);
}


int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  shellSort(a,n);
  return 0;
}