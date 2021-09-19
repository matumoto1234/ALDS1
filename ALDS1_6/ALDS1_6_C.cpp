#include<bits/stdc++.h>
using namespace std;

struct card{
  char mark;
  int num,index;
};

void swapCard(card& a,card& b){
  card temp=a;
  a=b;
  b=temp;
}

int Partition(vector<card>& a,int p,int r){
  int x=a[r].num;
  int i=p-1;
  
  for(int j=p;j<r;j++){
    if(a[j].num<=x){
      i++;
      swapCard(a[i],a[j]);
    }
  }
  swapCard(a[i+1],a[r]);
  return i+1;
}

void quicksort(vector<card>& a,int p,int r){
  if(p<r){
    int q=Partition(a,p,r);
    quicksort(a,p,q-1);
    quicksort(a,q+1,r);
  }
}

int main(){
  int n;
  cin>>n;
  vector<card> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i].mark>>a[i].num;
    a[i].index=i;
  }
  quicksort(a,0,n-1);
  bool flg=true;
  int max_i=-1,last=a[0].num;
  for(int i=0;i<n;i++){
    if(last!=a[i].num){
      max_i=a[i].index;
      last=a[i].num;
      continue;
    }
    if(max_i<a[i].index){
      max_i=a[i].index;
    }else{
      flg=false;
      break;
    }
  }
  cout<<(flg?"Stable":"Not stable")<<endl;
  for(int i=0;i<n;i++){
    cout<<a[i].mark<<' '<<a[i].num<<"\n";
  }
  return 0;
}