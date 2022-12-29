#include <stdio.h>
#include <stdlib.h>
struct Node *top;
struct Node {
  int data;
  struct Node *next;
};

void push(int value) {
  struct Node *newNode;
  newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  if (top == NULL) {
    newNode->next = NULL;
  } else {
    newNode->next = top;
  }
  top = newNode;
  printf("Node is Inserted\n\n");
}

int pop() {
  if (top == NULL) {
    printf("\nStack Underflow\n");
  } else {
    struct Node *temp = top;
    int temp_data = top->data;
    top = top->next;
    return temp_data;
  }
  return 0;
}

void display() {
  if (top == NULL) {
    printf("\nStack Underflow\n");
  } else {
    printf("The stack is \n");
    struct Node *temp = top;
    while (temp->next != NULL) {
      printf("%d--->", temp->data);
      temp = temp->next;
    }
    printf("%d--->NULL\n\n", temp->data);
  }
}

int main() {
  push(3);
  push(5);
  push(9);
  push(1);
  push(12);
  push(15);

  pop();
  display();

  return 0;
}