#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
}Node;

Node* list_create(int* ary, int n)
{
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

Node* list_reverse(Node* head)
{
	Node* p = head;
	Node* q = NULL;
	Node* r = NULL;
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}

Node* getNodeAt(Node* head, int index)
{
	int count = 0;
	Node* horse = head;
	while (horse != NULL)
	{
		if (count == index)
		{
			return horse;
		}
		count++;
		horse = horse->link;
	}

	return NULL;
}

int main(void)
{
	int n = 3;
	int ary[3] = { 10, 20, 30 };
	Node* head = NULL;
	head = list_create(ary, n);

	Node* cur = NULL;//현재 노드
	printf("------------------------변경 전-----------------------\n");
	for (int i = 0; i < n; i++)//출력
	{
		cur = getNodeAt(head, i);
		printf("%d\n", cur->data);
	}

	head = list_reverse(head);
	printf("------------------------변경 후-----------------------\n");
	for (int i = 0; i < n; i++)//출력
	{
		cur = getNodeAt(head, i);
		printf("%d\n", cur->data); 
	}
}