#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int INF = 100100100;

vector<int> compress(vector<int> a){
  int n=a.size();
  vector<int> res(n);
  map<int,int> mp;
  for(int i=0;i<n;i++){
    mp[a[i]]=i;
  }
  sort(a.begin(),a.end());
  for(int i=0;i<n;i++){
    res[mp[a[i]]]=i;
  }
  return res;
}

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  int minAll=INF;
  for(int i=0;i<n;i++){
    cin>>a[i];
    minAll=min(minAll,a[i]);
  }

  vector<int> ds = compress(a);
  vector<bool> arrived(n,false);
  int ans=0;
  for(int i=0;i<n;i++){
    if(arrived[i]) continue;
    
    int minv=INF;
    int sum=0;
    int size=0;
    int e=i;
    while(!arrived[e]){
      arrived[e]=true;
      minv=min(minv,a[e]);
      sum+=a[e];
      size++;
      e=ds[e];
    }
    if(size==1){
      continue;
    }
    int v1=(size-2)*minv+sum;
    int v2=(size+1)*minAll+sum+minv;
    if(minAll==minv) v2=v1;
    ans+=min(v1,v2);
  }
  cout<<ans<<endl;
  return 0;
}