#include<bits/stdc++.h>
using namespace std;
const int MAXN = 25;

struct Node{
  int p,l,r;
  int sibling,degree,depth,height;
};

// Tをグローバル変数にした。
// これで引数に毎回vector<Node>& Tを書かなくてすむ。
// nの入力より先に宣言する必要があるためMAXNで作っておく。
vector<Node> T(MAXN);


// Tをグローバル変数にした。
void getDepth(int index,int depth){
  T[index].depth=depth;

  // 子がないなら終了
  if(T[index].l==-1&&T[index].r==-1){
    return;
  }

  // 左の子があれば移動して深さを+1
  if(T[index].l!=-1){
    getDepth(T[index].l,depth+1);
  }
  // 右の子があれば移動して深さを+1
  if(T[index].r!=-1){
    getDepth(T[index].r,depth+1);
  }
  return;
}

// Tをグローバル変数にした。
// height(葉までの最大の辺の数)を決める。
// heightの決め方は、再帰で葉までたどった後に戻ってきた値の最大値としている。
int getHeight(int index){
  // degree(子の数)が0だったら葉。
  // 葉のときは0を返してそこから値が決まっていく。
  if(T[index].degree==0){
    return 0;
  }

  int maxHeight=-1;
  // 左の子があれば移動する。
  if(T[index].l!=-1){
    maxHeight=max(maxHeight,getHeight(T[index].l)+1);
  }
  // 右の子があれば移動する。
  if(T[index].r!=-1){
    maxHeight=max(maxHeight,getHeight(T[index].r)+1);
  }

  T[index].height=maxHeight;
  return maxHeight;
}

// 親がないなら根,子がないなら葉,それ以外は節
string name(int index){
  if(T[index].p==-1) return "root";
  else if(T[index].degree==0) return "leaf";
  else return "internal node";
}

// initialize(初期化)
// とりあえずやっておく。
void init(int n){
  for(int i=0;i<n;i++){
    T[i].p=-1;
    T[i].l=-1;
    T[i].r=-1;
    T[i].depth=-1;
    T[i].sibling=-1;
    T[i].degree=0;
    T[i].depth=0;
    T[i].height=0;
  }
}

// する必要はないけど、関数にまとめるとmainがスッキリするからまとめてしまう。
void input(int n){
  for(int i=0;i<n;i++){
    int id,left,right;
    cin>>id>>left>>right;

    T[id].l=left;
    T[id].r=right;

    // 子が-1じゃなければdegree(子の数)をそれぞれ+1する
    // 左の子の親を自分にする
    if(left!=-1){
      T[left].p=id;
      T[id].degree++;
    }
    // 右の子の親を自分にする
    if(right!=-1){
      T[right].p=id;
      T[id].degree++;
    }

    // 左と右の子があれば兄弟とする
    if(left!=-1&&right!=-1){
      T[left].sibling=right;
      T[right].sibling=left;
    }
  }
}

// これもする必要がないけどmainがスッキリするからという理由で関数にまとめる。
void output(int n){
  for(int i=0;i<n;i++){
    cout<<"node "<<i;
    cout<<": parent = "<<T[i].p;
    cout<<", sibling = "<<T[i].sibling;
    cout<<", degree = "<<T[i].degree;
    cout<<", depth = "<<T[i].depth;
    cout<<", height = "<<T[i].height;
    cout<<", "<<name(i);
    cout<<"\n";
  }
}

int main(){
  int n;
  cin>>n;

  // Tをグローバル変数にしたのでここで宣言はしない
  // n個を初期化
  init(n);

  // n個入力
  input(n);

  // 根を決める
  int root;
  for(int i=0;i<n;i++){
    if(T[i].p==-1) root=i;
  }

  // 根から深さ0で始める
  getDepth(root,0);

  // 高さを決める
  // これの返り値は無視してOK
  getHeight(root);

  // 出力
  output(n);
  return 0;
}