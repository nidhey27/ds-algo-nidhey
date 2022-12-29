#include <stdio.h>
#define SIZE 100

int QUEUE[SIZE];
int REAR = -1;
int FRONT = -1;

void enqueue() {
  int insert_item;
  if (REAR == SIZE - 1)
    printf("Overflow \n");
  else {
    if (FRONT == -1)

      FRONT = 0;
    printf("Element to be inserted in the Queue\n : ");
    scanf("%d", &insert_item);
    REAR = REAR + 1;
    QUEUE[REAR] = insert_item;
  }
}

void dequeue() {
  if (FRONT == -1 || FRONT > REAR) {
    printf("Underflow \n");
    return;
  } else {
    printf("Element deleted from the Queue: %d\n", QUEUE[FRONT]);
    FRONT = FRONT + 1;
  }
}

void show() {

  if (FRONT == -1)
    printf("Empty Queue \n");
  else {
    printf("Queue: \n");
    for (int i = FRONT; i <= REAR; i++)
      printf("%d ", QUEUE[i]);
    printf("\n");
  }
}