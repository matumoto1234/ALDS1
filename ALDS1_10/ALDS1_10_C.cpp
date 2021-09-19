#include<iostream>
#include<vector>
#include<string>
using namespace std;

int solve(string& s,string& t){
  vector<vector<int>> table(s.size(),vector<int>(t.size()));
  int flg=0;
  for(int i=0;i<s.size();i++){
    if(s[i]==t[0]){
      flg=1;
    }
    table[i][0]=flg;
  }
  flg=0;
  for(int j=0;j<t.size();j++){
    if(s[0]==t[j]){
      flg=1;
    }
    table[0][j]=flg;
  }


  for(int i=1;i<s.size();i++){
    for(int j=1;j<t.size();j++){
      if(s[i]==t[j]){
        table[i][j]=table[i-1][j-1]+1;
      }else{
        table[i][j]=max(table[i-1][j],table[i][j-1]);
      }
    }
  }
  
  int res=0;
  for(int i=0;i<s.size();i++){
    for(int j=0;j<t.size();j++){
      res=max(res,table[i][j]);
    }
  }
  return res;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    string s,t;
    cin>>s>>t;
    cout<<solve(s,t)<<endl;
  }
  return 0;
}