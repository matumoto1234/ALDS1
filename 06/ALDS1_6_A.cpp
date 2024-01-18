#include<bits/stdc++.h>
using namespace std;

vector<int> CountingSort(vector<int>& a, int k){
  vector<int> C(k+1,0);

  int n=a.size();
  for(int i=0;i<n;i++){
    C[a[i]]++;
  }

  for(int i=1;i<=k;i++){
    C[i]+=C[i-1];
  }

  vector<int> ret(n+1);
  for(int j=n-1;j>=0;j--){
    ret[C[a[j]]]=a[j];
    C[a[j]]--;
  }
  return ret;
}

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  vector<int> b = CountingSort(a,10000);
  for(int i=1;i<=n;i++){
    if(i-1){
      cout<<' ';
    }
    cout<<b[i];
  }
  cout<<endl;
  return 0;
}