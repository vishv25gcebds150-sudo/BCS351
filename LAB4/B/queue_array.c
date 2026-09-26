#include <stdio.h>
#define SIZE 5 
int queue[SIZE];
int front = -1, rear = -1;
int isFull() {
 return (front == (rear + 1) % SIZE);
}
int isEmpty() {
 return (front == -1);
}
void enqueue(int value) {
 if (isFull()) {
 printf("Queue is Full! Cannot enqueue %d\n", value);
 } else {
 if (front == -1) front = 0;
 rear = (rear + 1) % SIZE;
 queue[rear] = value;
 printf("%d enqueued to the queue.\n", value);
 }
}
void dequeue() {
 if (isEmpty()) {
 printf("Queue is Empty! Cannot dequeue.\n");
 } else {
 printf("%d dequeued from the queue.\n", queue[front]);
 if (front == rear) {
 front = rear = -1; 
 } else {
 front = (front + 1) % SIZE;
 }
 }
}
void peek() {
 if (isEmpty()) {
 printf("Queue is Empty!\n");
 } else {
 printf("Front element: %d\n", queue[front]);
 }
}
void display() {
 if (isEmpty()) {
 printf("Queue is Empty!\n");
 } else {
 printf("Queue elements: ");
 int i = front;
 while (1) {
 printf("%d ", queue[i]);
 if (i == rear) break;
 i = (i + 1) % SIZE;
 }
 printf("\n");
 }
}
int main() {
 int choice, value;
 while (1) {
 printf("\n--- Circular Queue Menu ---\n");
 printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter value to enqueue: ");
 scanf("%d", &value);
 enqueue(value);
 break;
 case 2:
 dequeue();
 break;
 case 3:
 peek();
 break;
 case 4:
 display();
 break;
 case 5:
 return 0;
 default:
 printf("Invalid choice! Try again.\n");
 }
 }
 return 0;
}