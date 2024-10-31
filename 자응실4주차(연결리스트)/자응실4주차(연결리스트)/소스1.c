#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* head = NULL;

void insert(int item)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = item;
	newnode->next = head;
	head = newnode;
}

void delete(int item)
{
	if (head == NULL)
		return;
	Node* cur = head;
	Node* pre = head;

	while (cur != NULL)
	{
		if (cur->data == item)
		{
			break;
		}
		pre = cur;
		cur = cur->next;
	}
	if (cur == head)
	{
		head = head->next;
		free(cur);
		return;
	}
	else
	{
		if (pre->next = NULL)
		{
			return;
		}
		else
		{
			pre->next = cur->next;
			free(cur);
			return;
		}
	}
}

void display()
{
	if (head == NULL)
	{
		return;
	}
	Node* cur = head;
	while (cur->next != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("%d\n", cur->data);
}

int main(void)
{
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	display();
	delete(2);
	display();
	insert(1);
}