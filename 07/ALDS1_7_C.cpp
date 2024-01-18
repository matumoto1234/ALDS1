#include<bits/stdc++.h>
using namespace std;
const int NIL = -1;

struct Node{
  Node() : p(NIL),l(NIL),r(NIL){};
  int p,l,r;
};

int getRoot(vector<Node>& tree,int i){
  if(tree[i].p==NIL){
    return i;
  }
  return getRoot(tree,tree[i].p);
}

void Preorder(vector<Node>& tree,int i){
  if(tree[i].l!=NIL){
    cout<<' '<<tree[i].l;
    Preorder(tree,tree[i].l);
  }
  if(tree[i].r!=NIL){
    cout<<' '<<tree[i].r;
    Preorder(tree,tree[i].r);
  }
}

void Inorder(vector<Node>& tree,int i){
  if(tree[i].l!=NIL){
    Inorder(tree,tree[i].l);
  }
  cout<<' '<<i;
  if(tree[i].r!=NIL){
    Inorder(tree,tree[i].r);
  }
}

void Postorder(vector<Node>& tree,int i){
  if(tree[i].l!=NIL){
    Postorder(tree,tree[i].l);
  }
  if(tree[i].r!=NIL){
    Postorder(tree,tree[i].r);
  }
  cout<<' '<<i;
}

int main(){
  int n;
  cin>>n;
  
  vector<Node> tree(n);

  for(int i=0;i<n;i++){
    int id,left,right;
    cin>>id>>left>>right;
    tree[id].l=left;
    tree[id].r=right;
    if(left!=NIL){
      tree[left].p=id;
    }
    if(right!=NIL){
      tree[right].p=id;
    }
  }

  int root=getRoot(tree,0);
  cout<<"Preorder\n";
  cout<<' '<<root;
  Preorder(tree,root);
  cout<<'\n';

  cout<<"Inorder\n";
  Inorder(tree,root);
  cout<<'\n';

  cout<<"Postorder\n";
  Postorder(tree,root);
  cout<<'\n';

  return 0;
}