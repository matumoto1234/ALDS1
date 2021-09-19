#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int to_i(char c) {
  switch (c) {
  case 'A':
    return 1;
    break;
  case 'C':
    return 2;
    break;
  case 'G':
    return 3;
    break;
  case 'T':
    return 4;
    break;
  default:
    break;
  }
  return 0;
}

ll s_to_ll(string& s){
  ll res=0,keta=4;
  int n=(int)s.size();
  for(int i=n-1;i>=0;i--){
    res+=to_i(s[i])*keta;
    keta*=4;
  }
  return res;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  vector<bool> deck(20000000,false);
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    string s,t;
    cin>>s>>t;
    if(s=="insert"){
      deck[s_to_ll(t)]=true;
      continue;
    }
    cout<<(deck[s_to_ll(t)]?"yes":"no")<<'\n';
  }
  return 0;
}