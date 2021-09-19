#include<bits/stdc++.h>
using namespace std;

struct card{
  char mark;
  int num,index;
};

void swapCard(card& a,card&b){
  card temp=a;
  a=b;
  b=temp;
}

void outputV(vector<card> v){
  for(int i=0;i<v.size();i++){
    if(i){
      cout<<' ';
    }
    cout<<v[i].mark<<v[i].num;
  }
  cout<<endl;
}

bool isStable(vector<card> v){
  int value=v[0].num;
  int last=v[0].index;
  for(int i=0;i<v.size();i++){
    if(value==v[i].num){
      if(last>v[i].index){
        return false;
      }
      last=v[i].index;
    }else{
      value=v[i].num;
      last=v[i].index;
    }
  }
  return true;
}

vector<card> BubbleSort(vector<card> v,int n){
  for(int i=0;i<n;i++){
    for(int j=n-1;j>=i+1;j--){
      if(v[j].num<v[j-1].num){
        swapCard(v[j],v[j-1]);
      }
    }
  }
  return v;
}

vector<card> SelectionSort(vector<card> v,int n){
  for(int i=0;i<n;i++){
    int minj=i;
    for(int j=i;j<n;j++){
      if(v[j].num<v[minj].num){
        minj=j;
      }
    }
    swapCard(v[i],v[minj]);
  }
  return v;
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n;
  cin>>n;
  vector<card> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i].mark>>a[i].num;
    a[i].index=i;
  }
  vector<card> v=BubbleSort(a,n);
  outputV(v);
  cout<<(isStable(v)?"Stable":"Not stable")<<endl;
  v=SelectionSort(a,n);
  outputV(v);
  cout<<(isStable(v)?"Stable":"Not stable")<<endl;
  return 0;
}