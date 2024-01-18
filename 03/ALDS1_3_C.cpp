#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

struct Node{
  int key;
  Node *prev,*next;
};

Node *nil;

Node* search_node(int key){
  Node *cur=nil->next;
  while(cur!=nil&&cur->key!=key){
    cur=cur->next;
  }
  return cur;
}

void init(){
  nil=(Node *)malloc(sizeof(Node));
  nil->next=nil;
  nil->prev=nil;
}

void insert(int key){
  Node *x=(Node*)malloc(sizeof(Node));
  x->key=key;

  x->next=nil->next;
  nil->next->prev=x;
  nil->next=x;
  x->prev=nil;
}

void delete_node(Node *t){
  if(t==nil){
    return;
  }
  t->prev->next=t->next;
  t->next->prev=t->prev;
  free(t);
}

void delete_first(){
  delete_node(nil->next);
}

void delete_last(){
  delete_node(nil->prev);
}

void print_node(){
  Node *t=nil->next;
  int i=0;
  while(1){
    if(t==nil){
      break;
    }
    if(i){
      cout<<' ';
    }
    i=1;
    cout<<t->key;
    t=t->next;
  }
  cout<<'\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin>>n;

  init();
  for(int i=0;i<n;i++){
    string com;
    cin>>com;

    if(com=="insert"){
      int x;
      cin>>x;
      insert(x);
      continue;
    }
    if(com=="delete"){
      int x;
      cin>>x;
      delete_node(search_node(x));
    }
    if(com=="deleteFirst"){
      delete_first();
    }
    if(com=="deleteLast"){
      delete_last();
    }
  }
  print_node();
  
  return 0;
}