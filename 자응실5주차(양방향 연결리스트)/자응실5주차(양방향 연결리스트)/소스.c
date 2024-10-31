#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

typedef struct node {
	int data;
	struct node* prev; //이전 노드를 가리킴
	struct node* next; //다음 노드를 가리킴
}Node;

typedef struct list {
	Node* head;
	Node* cur;
}List;


//초기화
void Init(List* list)
{
	list->head = NULL;
	list->cur = NULL;
}

void Insert(List* list, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));

	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	if (list->head == NULL)
	{
		list->head = newnode;
	}
	else
	{
		newnode->next = list->head;
		list->head->prev = newnode;
		list->head = newnode;
	}
}

void Delete(List* list, int data)
{
	list->cur = list->head;
	if (list->head == NULL)
	{
		printf("리스트가 없습니다.\n");
		return;
	}
	else
	{
		while (list->cur != NULL)
		{
			if (list->cur->data == data)
			{
				if (list->cur == list->head)//첫 번째 노드 삭제
				{
					list->head = list->head->next;
					list->head->prev = NULL;
				}
				else if (list->cur->next == NULL)//마지막노드 삭제
				{
					list->cur->prev->next = NULL;
				}
				else//중간노드 삭제
				{
					list->cur->prev->next = list->cur->next;
					list->cur->next->prev = list->cur->prev;
				}
				free(list->cur);
				return;
			}
			else
			{
				list->cur = list->cur->next;
			}
		}
		printf("찾는 값이 없습니다.\n");
	}
}

void Display(List* list)
{
	if (list->head == NULL)
	{
		printf("리스트가 없습니다.\n");
		return;
	}
	else
	{
		list->cur = list->head;

		printf("오른쪽 방향 : \n");
		while (list->cur->next != NULL)
		{
			printf("%d ->", list->cur->data);
			list->cur = list->cur->next;
		}
		printf("%d \n", list->cur->data);

		printf("왼쪽 방향 : \n");
		while (list->cur->prev != NULL)
		{
			printf("%d ->", list->cur->data);
			list->cur = list->cur->prev;
		}
		printf("%d \n", list->cur->data);
	}
}

void main()
{
	List list;
	int select = 0;
	int data;
	Init(&list);

	while (select != 4)
	{
		printf("1)추가\n2)삭제\n3)출력\n4)종료\n-------------\n");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			printf("값 입력 : ");
			scanf("%d", &data);
			Insert(&list, data);
			Display(&list);
			break;
		case 2:
			printf("값 입력 : ");
			scanf("%d", &data);
			Delete(&list, data);
			Display(&list);
			break;
		case 3:
			Display(&list);
			break;
		case 4:
			break;
		default:
			break;
		}
	}
}