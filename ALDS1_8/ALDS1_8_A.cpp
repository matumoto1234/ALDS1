#include<bits/stdc++.h>
using namespace std;

struct binaryTree{
  struct node{
    int key;
    node *p,*l,*r;
  };

  const int INF = (int)2e9+1;
  node *nil,*root;

  // initialize:初期化
  void init(){
    //nil=makeNode(INF);
    nil=(node*)malloc(sizeof(node));
    nil->key=INF;
    nil->p=nil;
    nil->l=nil;
    nil->r=nil;
    root=makeNode(INF);
  }

  // 値(value)をkeyにして作成した節点を返す
  node* makeNode(int v){
    node *res=(node*)malloc(sizeof(node));
    res->key=v;
    res->p=nil;
    res->l=nil;
    res->r=nil;
    return res;
  }

  // 新しい節点を木に挿入する
  void insert(int new_key){
    node *z=makeNode(new_key);
    node *x=root;
    node *y=nil;

    // keyがzの節点をどこに入れるか探す
    // 根から辿っていき、xより大きいか小さいかで右に進むか左に進むかを判定
    while(x != nil){
      y=x;
      int vx=x->key;
      int vz=z->key;
      if(vx >= vz){
        x=x->l;
      }else{
        x=x->r;
      }
    }
    // whileが終わるときにはxはnilになっている

    // xが今いるところにzを挿入する
    // 新しい節点zを挿入するには次の2つを実行する
    // ・zの親を決める
    // ・zの親から見て左の子か右の子かを判定する

    // ・zの親を決める
    z->p = y;

    // z->pがnilなのはroot
    if(z->p->key == nil->key){
      root=z;
      return;
    }

    // ・zの親から見て左の子か右の子かを判定する
    if(z->p->key >= z->key){
      z->p->l = z;
    }else{
      z->p->r = z;
    }
  }

  // 先行順巡回(節、左、右)の順で出力する
  void preorder(node *a){
    if(a == nil) return;

    cout<<' '<<a->key;
    preorder(a->l);
    preorder(a->r);
  }

  // 中間順巡回(左、節、右)の順で出力する
  void inorder(node *a){
    if(a == nil) return;

    inorder(a->l);
    cout<<' '<<a->key;
    inorder(a->r);
  }

  void print(){
    inorder(root);
    cout<<'\n';
    preorder(root);
    cout<<'\n';
  }
};

int main(){
  binaryTree T;
  T.init();

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    string s;
    cin>>s;
    if(s=="print"){
      T.print();
      continue;
    }
    int x;
    cin>>x;
    if(s=="insert"){
      T.insert(x);
    }
  }

  return 0;
}