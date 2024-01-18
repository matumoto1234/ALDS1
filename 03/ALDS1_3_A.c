#include <stdbool.h>
#include <stdio.h>
#include<stdlib.h>

typedef struct {
  int array[100000];
  int index;
} stack;

stack st;

void init(int sz) {
  for (int i = 0; i < sz; i++) {
    st.array[i] = 0;
  }
}

void push(int key) {
  st.array[st.index] = key;
  st.index++;
}

int pop() {
  st.index--;
  return st.array[st.index];
}

bool is_operand(char op) {
  if (op == '+' || op == '-' || op == '*') {
    return true;
  }
  return false;
}

int main() {
  init(100000);
  while (1) {
    int status;
    char str[100];

    status = scanf("%s", str);
    if (status == EOF) {
      break;
    }

    if (is_operand(str[0])) {
      int b = pop();
      int a = pop();
      switch (str[0]) {
      case '+':
        push(a + b);
        break;
      case '-':
        push(a - b);
        break;
      case '*':
        push(a * b);
        break;
      }
      continue;
    }
    push(atoi(str));
  }
  printf("%d\n", st.array[0]);
  return 0;
}