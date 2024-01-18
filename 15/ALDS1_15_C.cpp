#include<bits/stdc++.h>
using namespace std;

struct job{
  int s,t;
};

bool asc(const job& l,const job& r){
  return l.t==r.t?l.s<r.s:l.t<r.t;
}

int main(){
  int n;
  cin>>n;
  vector<job> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i].s>>a[i].t;
  }
  sort(a.begin(),a.end(),asc);
  
  int ans=0;
  int last=-1;
  for(int i=0;i<n;i++){
    if(last<a[i].s){
      ans++;
      last=a[i].t;
    }
  }
  cout<<ans<<endl;
}