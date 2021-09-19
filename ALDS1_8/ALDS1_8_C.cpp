#include<iostream>
#include<string>
using namespace std;
const int INF = 2e9+1;

struct Node{
  int key;
  Node *l,*r,*p;
};

Node *NIL,*root;

Node* make_node(int _key){
  Node *res;
  //res=(Node*)malloc(sizeof(Node));
  res= new Node;
  res->key=_key;
  res->p=NIL;
  res->l=NIL;
  res->r=NIL;
  return res;
}

void init(){
  NIL=make_node(0);
  root=make_node(INF);
}

void insert(int _key){
  Node *x=root;
  Node *y=NIL;
  Node *z=make_node(_key);
  while(x!=NIL){
    y=x;
    if(z->key<x->key){
      x=x->l;
    }else{
      x=x->r;
    }
  }

  z->p=y;
  if(z->p==NIL){
    root=z;
    //free(z);
    delete z;
    return;
  }

  if(z->key<y->key){
    y->l=z;
  }else{
    y->r=z;
  }
}

Node* find(int _key){
  Node *x=root;

  while(x!=NIL){
    if(x->key==_key){
      return x;
    }

    if(_key<x->key){
      x=x->l;
    }else{
      x=x->r;
    }
  }
  return NIL;
}

Node* getMinimum(Node *x){
  while(x->l!=NIL){
    x=x->l;
  }
  return x;
}

Node* getSuccessor(Node *x){
  if(x->r!=NIL){
    return getMinimum(x->r);
  }

  Node *y=x->p;
  while(y!=NIL&&x==y->r){
    x=y;
    y=y->p;
  }
  return y;
}

void delete_node(int _key){
  Node *z=find(_key);

  if(z==NIL){
    return;
  }

  Node *y;
  if(z->l==NIL||z->r==NIL){
    y=z;
  }else{
    y=getSuccessor(z);
  }

  Node *x;
  if(y->l!=NIL){
    x=y->l;
  }else{
    x=y->r;
  }

  if(x!=NIL){
    x->p=y->p;
  }

  if(y->p==NIL){
    root=x;
  }else if(y==y->p->l){
    y->p->l=x;
  }else{
    y->p->r=x;
  }

  if(y!=z){
    z->key=y->key;
  }
}

void in_order(Node *x){
  if(x->l!=NIL){
    in_order(x->l);
  }
  if(x!=root){
    cout << ' ' << x->key;
  }
  if(x->r!=NIL){
    in_order(x->r);
  }
}

void pre_order(Node *x){
  if(x!=root){
    cout << ' ' << x->key;
  }
  if(x->l!=NIL){
    pre_order(x->l);
  }
  if(x->r!=NIL){
    pre_order(x->r);
  }
}

void print(){
  in_order(root);
  cout<<'\n';
  pre_order(root);
  cout<<'\n';
}


int main(){
  init();
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    if(s=="print"){
      print();
      continue;
    }
    int x;
    cin>>x;
    if(s=="insert"){
      insert(x);
    }
    if(s=="find"){
      bool flg=(find(x)!=NIL);
      cout<<(flg?"yes":"no")<<'\n';
    }
    if(s=="delete"){
      delete_node(x);
    }
  }
  return 0;
}