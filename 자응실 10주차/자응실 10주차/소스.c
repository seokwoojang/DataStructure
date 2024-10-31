#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* front = NULL;
Node* rear = NULL;

void en(int data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	if (rear == NULL) {
		rear = newnode;
		front = newnode;
		return;
	}
	rear->next = newnode;
	rear = newnode;
}

int de() {
	if (rear == NULL) {
		return;
	}
	Node* cur = front;
	int temp = front->data;
	if (front == rear) {
		front = front->next;
		rear == NULL;
	}
	else
	{
		front = front->next;
	}
	free(cur);
	return temp;
}

void main() {
	en(1);
	en(2);
	en(3);
	en(4);
	printf("%d\n", de());
	printf("%d\n", de());
	printf("%d\n", de());
	printf("%d\n", de());
}