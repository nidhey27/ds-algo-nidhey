#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

int length(struct Node *ptr) {
  int count = 0;

  while (ptr != NULL) {
    ptr = ptr->next;
    count += 1;
  }

  return count;
}
void linkedListTraversal(struct Node *ptr) {

  if (length(ptr) == 0) {
    printf("Linked List is Empty!!!\n");
    return;
  }

  while (ptr != NULL) {
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
  }
}

struct Node *insertAtbeginning(struct Node *head, int data) {
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

  ptr->data = data;
  ptr->next = head;

  return ptr;
}

struct Node *insertAtEnd(struct Node *head, int data) {
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

  struct Node *p = head;
  while (p->next != NULL) {
    p = p->next;
  }

  p->next = ptr;
  ptr->data = data;
  return head;
}

int main() {

  struct Node *head;
  linkedListTraversal(head);
  head = (struct Node *)malloc(sizeof(struct Node));
  printf("Length Of Linked List is: %d\n", length(head));

  head->data = 03;
  head->next = NULL;
  printf("Length Of Linked List is: %d\n", length(head));
  linkedListTraversal(head);

  head = insertAtbeginning(head, 27);
  head = insertAtbeginning(head, 111);
  linkedListTraversal(head);
  printf("Length Of Linked List is: %d\n", length(head));
  return 0;
}