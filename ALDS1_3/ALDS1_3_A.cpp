#include<bits/stdc++.h>
using namespace std;

void pushResult(stack<int>& st,char op){
  if(op=='+'){
    int temp=st.top();
    st.pop();
    temp+=st.top();
    st.pop();
    st.push(temp);
  }else if(op=='-'){
    int temp=st.top();
    st.pop();
    temp=st.top()-temp;
    st.pop();
    st.push(temp);
  }else{
    int temp=st.top();
    st.pop();
    temp*=st.top();
    st.pop();
    st.push(temp);
  }
}

void outStack(stack<int> st){
  int i=0;
  while(!st.empty()){
    cout<<"i="<<i<<' '<<st.top()<<endl;
    st.pop();
    i++;
  }

}

int main(){
  string s;
  stack<int> st;
  while(cin>>s){
    if('0'<=s[0]&&s[0]<='9'){
      st.push((int)stoi(s));
      continue;
    }
    pushResult(st,s[0]);
  }
  cout<<st.top()<<endl;

  return 0;
}