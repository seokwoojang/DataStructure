/*#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* queue = NULL;
Node* front = NULL;
Node* rear = NULL;

int empty() {
	if (rear == NULL)
	{
		return 1;
	}
	else
		return 0;
}

void enqueue(int data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = NULL;
	if (rear == NULL)
	{
		rear = newnode;
		front = newnode;
	}
	else
	{
		rear->next = newnode;
		rear = newnode;
	}
}

int dequeue()
{
	if (empty())
	{
		printf("������ ���������");
		return -1;
	}
	else
	{
		if (front == rear)
		{
			int temp = front->data;
			front = front->next;
			rear = NULL;
			return temp;
		}
		else
		{
			int temp = front->data;
			front = front->next;
			return temp;
		}
	}
}

// �ϳ� ������ �� ������ �� front,rear �Ѵ� null�� �������

//int main(void)
//{
//	enqueue(1);
//	enqueue(2);
//	enqueue(3);
//	enqueue(4);
//	printf("%d\n", dequeue());
//	printf("%d\n", dequeue());
//	printf("%d\n", dequeue());
//	printf("%d\n", dequeue());
//	printf("%d\n", dequeue());
//	
//}*/