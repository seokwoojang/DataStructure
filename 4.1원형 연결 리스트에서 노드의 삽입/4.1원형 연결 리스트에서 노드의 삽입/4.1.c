#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
}Node;

Node* list1(Node* head, int item)
{
	Node* temp = head;
	while (temp->link != head)
	{
		temp = temp->link;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = item;
	if (head == NULL)
	{
		head = newNode;
		newNode->link = newNode;
	}
	else
	{
		newNode->link = head;
		temp->link = newNode;
		head = newNode;
	}
	return head;
}

Node* list2(Node* head, int item)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = item;
	if (head == NULL)
	{
		head = newNode;
		newNode->link = newNode;
	}
	else
	{
		newNode->link = head->link;
		head->link = newNode;
	}
	return head;
}
Node* getNodeAt(Node* head, int index)
{
	Node* horse = head;
	int count = 0;
	while (horse != NULL)
	{
		if (count == index)
		{
			return horse;
		}
		count++;
		horse = horse->link;
	}
}

//void display(Node* head)
//{
//	Node* p;
//	if (head == NULL)return;
//	p = head->link;
//	do {
//		printf("%d->", p->data);
//		p = p->link;
//	} while (p != head);
//	printf("%d", p->data);
//}
int main(void)
{
	Node* head = NULL;
	for (int i = 0; i < 5; i++)
	{
		head = list2(head, i);
	}
	/*for (int i = 1; i < 4; i++)
	{
		head = list1(head, i);
	}*/
	printf("----------------------------------------\n");
	Node* cur = NULL;
	//display(head);
	for (int i = 0; i < 10; i++)
	{
		printf("%d->", head->data);
		head = head->link;
	}
}