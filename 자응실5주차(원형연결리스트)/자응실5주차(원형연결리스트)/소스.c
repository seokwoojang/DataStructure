#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

/*typedef struct node {
	int data;
	struct node* next;
}Node;

typedef struct list {
	Node* tail;//마지막
	Node* cur;//현재
	Node* be;//이전 노드
}List;


//초기화
void Init(List* list)
{
	list->tail = NULL;
	list->cur = NULL;
	list->be = NULL;
}

//맨 앞에 삽입
void Insert(List* list, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	if (list->tail == NULL)
	{
		list->tail = newnode;
		newnode->next = newnode;
	}
	else
	{
		newnode->next = list->tail->next;
		list->tail->next = newnode;
	}
}

void Delete(List* list, int data)
{
	if (list->tail == NULL)
	{
		printf("리스트가 없습니다.\n");
		return;
	}
	list->cur = list->tail->next;//현재
	list->be = list->tail;//이전

	while (1)
	{
		if (list->cur->data == data)
		{
			list->be->next = list->cur->next;
			if (list->cur == list->tail)
			{
				list->tail = list->be;
			}
			free(list->cur);
			return;
		}
		else
		{
			list->be = list->cur;
			list->cur = list->cur->next;
		}
		//없는 값이 입력되면 탈출
		if (list->be == list->tail)
			return;
	}
}

void Display(List* list)
{
	if (list->tail == NULL) {
		printf("리스트가 없습니다.\n");
		return;
	}
	list->cur = list->tail->next;

	while (list->cur != list->tail)
	{
		printf("%d -> ", list->cur->data);
		list->cur = list->cur->next;
	}
	printf("%d -> \n", list->cur->data);
	printf("-----------------------------------------------\n");

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
*/