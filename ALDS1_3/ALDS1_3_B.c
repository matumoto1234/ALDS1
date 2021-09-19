#include<stdio.h>

#define SIZE 200000

typedef struct{
  char name[11];
  int time;
}process;

typedef struct{
  process array[SIZE];
  int head,tail;
  int is_empty,is_full;
}queue;

queue Q;

void init(){
  Q.head=Q.tail=0;
  Q.is_empty=Q.is_full=0;
}

void push(process x){
  if(Q.is_full==1){
    return;
  }
  Q.is_empty=0;
  Q.array[Q.tail++]=x;
  if(Q.tail>SIZE){
    Q.tail=0;
  }
  if(Q.head==Q.tail){
    Q.is_full=1;
  }
}

void pop(){
  if(Q.is_empty==1){
    return;
  }
  Q.is_full=0;
  Q.head++;
  if(Q.head>SIZE){
    Q.head=0;
  }
  if(Q.head==Q.tail){
    Q.is_empty=1;
  }
}

process top(){
  return Q.array[Q.head];
}

int empty() {return Q.is_empty;}

int main(){
  init();
  int n,q;
  scanf("%d %d",&n,&q);
  for(int i=0;i<n;i++){
    process input;
    scanf("%s %d",input.name,&input.time);
    push(input);
  }
  int sum=0;
  while(!empty()){
    process temp=top();
    pop();

    if(temp.time<=q){
      sum+=temp.time;
      printf("%s %d\n",temp.name,sum);
      continue;
    }
    sum+=q;
    temp.time-=q;
    push(temp);
  }
  return 0;
}