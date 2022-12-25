// Insert Start - O(1)
// Insert End - O(n)
// Forward/Reverse Traverse - O(n)
// Delete at Start O(1)
// Delete at End-Index O(n)
#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *prev;
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

void linkedForwardListTraversal(struct Node *ptr) {

  if (length(ptr) == 0) {
    printf("Linked List is Empty!!!\n");
    return;
  }

  printf("************ Forward Traversal ************\n");
  while (ptr != NULL) {
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
  }
}

struct Node *getLastNode(struct Node *head) {
  struct Node *tail = head;

  while (tail->next != NULL) {
    tail = tail->next;
  }
  return tail;
}

void linkedReverseListTraversal(struct Node *ptr) {
  if (length(ptr) == 0) {
    printf("Linked List is Empty!!!\n");
    return;
  }

  ptr = getLastNode(ptr);

  printf("************ Reverse Traversal ************\n");
  while (ptr != NULL) {
    printf("Element: %d\n", ptr->data);
    ptr = ptr->prev;
  }
}

struct Node *insert_at_beginning(struct Node *head, int data) {
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

  if (length(head) == 0) {
    // printf(" Empty");
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
  } else {
    head->prev = ptr;
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = head;
  }

  // printf("########## %d ########## \n", ptr->data);

  return ptr;
}

struct Node *insert_at_end(struct Node *head, int data) {

  if (length(head) == 0) {
    head = insert_at_beginning(head, data);
    return head;
  }

  struct Node *p = head;
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

  while (p->next != NULL) {
    p = p->next;
  }
  p->next = ptr;
  ptr->prev = p;
  ptr->data = data;
  ptr->next = NULL;

  //   printf("########## %d ########## \n", ptr->data);
  return head;
}

struct Node *delete_at_index(struct Node *head, int index) {

  if (length(head) == 0) {
    printf("Linked List is Empty!!");
    return head;
  }

  if (index > length(head) - 1 || index < 0) {
    printf("Invalid Index\n");
    return head;
  }

  if (index == 0) {
    head = head->next;
    head->prev = NULL;
    return head;
  }

  int count = 0;
  struct Node *ptr = head;
  while (ptr != NULL) {
    if (index - 1 == count) {
      ptr->next->prev = ptr;
      ptr->next = ptr->next->next;
      break;
    }

    ptr = ptr->next;
    count += 1;
  }

  return head;
}

int main() {

  struct Node *head;
  printf("Length: %d\n", length(head));

  // head = (struct Node *)malloc(sizeof(struct Node));
  head = insert_at_end(head, 888);
  // head->prev = NULL;
  // head->data = 1;
  // head->next = NULL;

  printf("Length: %d\n", length(head));

  head = insert_at_beginning(head, 20);
  head = insert_at_beginning(head, 30);
  head = insert_at_end(head, 40);
  head = insert_at_end(head, 50);
  head = insert_at_end(head, 999);

  linkedForwardListTraversal(head);
  head = delete_at_index(head, 0);
  head = delete_at_index(head, 2);
  head = delete_at_index(head, 3);
  linkedReverseListTraversal(head);

  return 0;
}