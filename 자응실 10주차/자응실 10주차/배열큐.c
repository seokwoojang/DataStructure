/*#include<stdio.h>

#define MAX_Q_Size 10
char queue[MAX_Q_Size];
int front, rear;

int is_Full() {
	return front == (rear + 1) % MAX_Q_Size;
}

int is_Empty() {
	return front == rear;
}

void Enqueue(char al) {
	if (is_Full())
	{
		printf("공간이 없음\n");
		return;
	}
	else
	{
		rear = (rear + 1) % MAX_Q_Size;
		queue[rear] = al;
	}
}

char Dequeue()
{
	if (is_Empty())
	{
		printf("공간이 비워져있음\n");
		return 1;
	}
	else
	{
		front = (front + 1) % MAX_Q_Size;
		return queue[front];
	}
}

void display()
{
	int temp = (front + 1) % MAX_Q_Size;

	printf("\n\n");
	while (temp != rear) {
		printf("%3c", queue[temp]);
		temp = (temp + 1)% MAX_Q_Size;
	}
	printf("%3c", queue[temp]);
	printf("\n\n");
}

void main() {
	front = 0;
	rear = 0;

	char al = 'A';

	for (int i = 0; i < MAX_Q_Size; i++) {
		Enqueue(al + i);display();
	}
	

	for (int i = 0; i < MAX_Q_Size; i++) {
		char temp = Dequeue();
		printf("%c\n", temp);
	}
	
}*/