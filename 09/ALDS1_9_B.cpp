#include<iostream>
#include<vector>
using namespace std;

int h;

void maxHeapify(vector<int>& a,int idx){
  int l=idx*2;
  int r=idx*2+1;
  // 左の子、自分、右の子で値が最大のノードを選ぶ
  int largest;
  if(l<=h&&a[l]>a[idx]){
    largest=l;
  }else{
    largest=idx;
  }
  if(r<=h&&a[r]>a[largest]){
    largest=r;
  }
  if(largest!=idx){
    swap(a[idx],a[largest]);
    maxHeapify(a,largest);
  }

}

void buildMaxHeap(vector<int>& a){
  for(int i=h/2;i>=1;i--){
    maxHeapify(a,i);
  }
}

int main(){
  cin>>h;
  vector<int> a(h+1);
  for(int i=1;i<=h;i++){
    cin>>a[i];
  }
  buildMaxHeap(a);
  for(int i=1;i<=h;i++){
    cout<<' '<<a[i];
  }
  cout<<'\n';
  return 0;
}