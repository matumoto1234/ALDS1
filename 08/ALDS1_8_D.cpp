#include <iostream>
#include <limits>
using namespace std;

template <typename T> class Treap {
public:
  
  Node* nil() { return NIL; }

  Node* root() { return ROOT; }

  Treap(){
    init();
  }

  void init(){
    NIL->key=inf();
    NIL->priority=inf();
    NIL->l=NIL;
    NIL->r=NIL;
    NIL->p=NIL;
    ROOT->key=inf();
    ROOT->priority=inf();
    ROOT->p=NIL;
    ROOT->l=NIL;
    ROOT->r=NIL;
  }

  Node* insert(Node *t,int k,int p){
    if(t==NIL) Node()
  }

private:
  struct Node{
    T key,priority;
    Node *l,*r,*p;
  };

  Node *ROOT,*NIL;

  T inf() { return numeric_limits<T>::max(); }

};

struct test{
  int _key;
  test abc;
};

int main() {
  test a;
  test b;
  
}