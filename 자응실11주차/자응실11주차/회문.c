/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)
#define MAX_LEN 50

typedef struct Node {
	char data;
	struct Node* next;
}Node;

typedef struct list {
	Node* top;
	Node* front;
	Node* rear;
}List;

void push(List* list,char ch)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = ch;
	newnode->next = list->top;
	list->top = newnode;
}

char pop(List* list)
{
	Node* cur = list->top;
	if (list->top == NULL)
	{
		printf("스택이 없음\n");
		return 0;
	}
	char temp = list->top->data;
	list->top = list->top->next;
	free(cur);
	return temp;
}

void equeue(List* list,char ch)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = ch;
	if (list->rear == NULL)
	{
		list->front = newnode;
		list->rear = newnode;
	}
	list->rear->next = newnode;
	list->rear = newnode;
}

char dequeue(List* list)
{
	Node* cur = list->front;
	if (list->rear = NULL)
	{
		printf("큐가 비어있음\n");
		return 0;
	}
	char temp = list->front->data;
	list->front = list->front->next;
	free(cur);
	return temp;
}

int Match(List* list,int n)
{
	for (int i = 0; i < n; i++)
	{
		char a = pop(list);
		char b = dequeue(list);
		if (a != b)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

void main(void)
{
	List list;
	list.front = NULL;
	list.rear = NULL;
	list.top = NULL;

	char input[MAX_LEN];
	printf("값 입력 : ");
	scanf("%s", input);

	for (int i = 0; i < strlen(input); i++)
	{
		push(&list, input[i]);
		equeue(&list, input[i]);
	}

	
	if (Match(&list,strlen(input)))
	{
		printf("\n%s는 회문입니다.\n\n", input);
	}
	else
	{
		printf("\n%s는 아닙니다.\n\n", input);
	}
}*/