#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

typedef struct node {
	int data;
	struct node* next;
}Node;

Node* head = NULL;

void insert(int item)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = item;
	if (head == NULL)
	{
		head = newnode;
		newnode->next = newnode;
	}
	else
	{
		newnode->next = head->next;
		head->next = newnode;
	}
}

void delete(int item)
{
	if (head == NULL)
		return;
	Node* cur = head->next;
	Node* pre = head;
	while (cur->next!=head)
	{
		if (cur->data == item)
		{
			pre = cur->next;
			if (cur == head)
			{
				head = pre;
			}
			free(cur);
			return;
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
		if (pre->next = head)
			return;
	}
}

void display()
{
	if (head == NULL)
	{
		return;
	}
	Node* cur = head;
	printf("%d->", cur->data);
	cur = cur->next;
	printf("%d->", cur->data);
	cur = cur->next;
	printf("%d->", cur->data);
	cur = cur->next;
	printf("%d->", cur->data);
	cur = cur->next;
}

int main(void)
{
	insert(1);
	insert(2);
	insert(3);
	display();
	delete(1);
	printf("\n");
	display();
}