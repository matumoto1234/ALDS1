#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;
  cin>>n;
  int ans=0;

  ans+=n/25;
  n-=n/25*25;
  
  ans+=n/10;
  n-=n/10*10;

  ans+=n/5;
  n-=n/5*5;

  ans+=n/1;

  cout<<ans<<endl;
  return 0;
}