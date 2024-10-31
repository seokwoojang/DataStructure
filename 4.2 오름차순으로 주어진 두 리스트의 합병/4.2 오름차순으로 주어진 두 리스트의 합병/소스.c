#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
}Node;

Node* list_create(int* ary, int n) {
	Node* head = NULL;
	for (int i = 0; i < n; i++)
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = ary[i];
		newNode->link = head;
		head = newNode;
	}
	return head;
}

Node* attach(Node* p, int data)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->link = NULL;
	if (p != NULL)
	{
		p->link = temp;
	}
	return temp;
}

Node* List_Merge(Node* a, Node* b)
{
	Node* c = NULL;
	Node* head = NULL;
	if (a->data < b->data)
	{
		c = attach(c, a->data);
		a = a->link;
	}
	else
	{
		c = attach(c, b->data);
		b = b->link;
	}
	head = c;
	while (a != NULL && b != NULL)
	{
		if (a->data < b->data)
		{
			c = attach(c, a->data);
			a = a->link;
		}
		else
		{
			c = attach(c, b->data);
			b = b->link;
		}
	}
	while (a != NULL)
	{
		c = attach(c, a->data);
		a = a->link;
	}
	while (b != NULL)
	{
		c = attach(c, b->data);
		b = b->link;
	}
	return head;
}



void display(Node* p)
{
	if (p == NULL)
	{
		printf("출력할게 없음.");
		return;
	}
	do {
		printf("%d ", p->data);
		p = p->link;
	}while(p != NULL);
	return;
}

int main(void)
{
	int ary[3] = { 20,15,10 };
	int ary2[3] = { 25,16,13 };
	Node* head1 = NULL;
	Node* head2 = NULL;
	Node* head3 = NULL;
	head1 = list_create(ary, 3);
	head2 = list_create(ary2, 3);
	head3 = List_Merge(head1, head2);
	display(head3);
}