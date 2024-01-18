#include<bits/stdc++.h>
using namespace std;

struct query{
  string name;
  int time;
};

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n,q;
  cin>>n>>q;
  queue<query> Q;
  query temp;

  for(int i=0;i<n;i++){
    cin>>temp.name>>temp.time;
    Q.push(temp);
  }
  long long sum_time=0;
  while(!Q.empty()){
    if(Q.front().time-q<=0){
      cout<<Q.front().name<<' '<<Q.front().time+sum_time<<'\n';
      sum_time+=Q.front().time;
      Q.pop();
      continue;
    }
    sum_time+=q;
    Q.front().time-=q;
    Q.push(Q.front());
    Q.pop();
  }
  return 0;
}