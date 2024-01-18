#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
  string s,t;
  cin>>s>>t;
  if(s.size()<t.size()){
    return 0;
  }
  for(int i=0;i<=s.size()-t.size();i++){
    bool flg=true;
    for(int j=0;j<t.size();j++){
      if(s[i+j]!=t[j]){
        flg=false;
        break;
      }
    }
    if(flg){
      cout<<i<<endl;
    }
  }
  return 0;
}