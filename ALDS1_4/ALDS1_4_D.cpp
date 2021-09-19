#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
const ll MAXN = 100000;

ll n,k;
vector<ll> w(MAXN);
bool solve(ll p){
  ll cnt=1;
  ll sum=0;
  for(ll i=0;i<n;i++){
    if(w[i]>p) return false;
    if(sum+w[i]>p){
      sum=w[i];
      cnt++;
    }else{
      sum+=w[i];
    }
  }
  if(cnt>k) return false;
  return true;
}

int main(){
  cin>>n>>k;
  for(ll i=0;i<n;i++){
    cin>>w[i];
  }

  ll l=0,r=INT64_MAX/2;
  while(r-l>1){
    ll mid=(l+r)/2;
    if(solve(mid)){
      r=mid;
    }else{
      l=mid;
    }
  }

  cout<<r<<endl;
  return 0;
}