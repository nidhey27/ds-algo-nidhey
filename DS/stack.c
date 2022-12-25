#include <stdio.h>

int STACK_MAX_SIZE = 10;
int STACK_TOP = -1;

int isempty() {

  if (STACK_TOP == -1)
    return 1;
  else
    return 0;
}

int isfull() {

  if (STACK_TOP == STACK_MAX_SIZE)
    return 1;
  else
    return 0;
}

int push(int data, int stack[]) {

  if (!isfull()) {
    STACK_TOP = STACK_TOP + 1;
    stack[STACK_TOP] = data;
  } else {
    printf("***** STACK OVERFLOW ****\n");
  }
  return data;
}

int pop(int stack[]) {
  int data;

  if (!isempty()) {
    data = stack[STACK_TOP];
    STACK_TOP = STACK_TOP - 1;
    return data;
  } else {
    printf("***** STACK UNDERFLOW ****\n");
  }
  return 0;
}

int peek(int stack[]) { return stack[STACK_TOP]; }

int main() {
  int stack[STACK_MAX_SIZE];

  // push items on to the stack
  push(3, stack);
  push(5, stack);
  push(9, stack);
  push(1, stack);
  push(12, stack);
  push(15, stack);

  printf("Element at top of the stack: %d\n", peek(stack));
  printf("Elements: \n");

  // print stack data
  while (!isempty()) {
    int data = pop(stack);
    printf("%d\n", data);
  }

  printf("Stack full: %s\n", isfull() ? "true" : "false");
  printf("Stack empty: %s\n", isempty() ? "true" : "false");

  return 0;
}