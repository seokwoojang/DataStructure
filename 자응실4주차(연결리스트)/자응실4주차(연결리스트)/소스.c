#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

/*typedef struct Node {
	int data;
	struct Node* next;
}Node;

//써도되고 안써도됨
struct List {
	Node* head;//맨 앞
	Node* cur;//현재 노드
	Node* be;//이전 노드
};

void Initiailztion(struct List* list)
{
	list->be = NULL;
	list->cur = NULL;
	list->head = NULL;
}

void LinkedInsert(struct List* list, int num)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = num;
	newNode->next = list->head;
	list->head = newNode;
}

int LinkedRemove(struct List* list, int num)
{
	if (list->head == NULL)
	{
		return NULL;
	}
	list->be = list->head;//이전 노드
	list->cur = list->head;//삭제 노드
	while (list->cur != NULL)
	{
		if (list->cur->data == num)
		{
			break;
		}

		list->be = list->cur;
		list->cur = list->cur->next;
	}
	if (list->cur==list->head)
	{
		list->head = list->head->next;
	}
	else
	{
		if (list->be->next == NULL)
		{
			return 0;
		}
		else
		{
			list->be->next = list->cur->next;

		}
	}
	free(list->cur);
	return 1;
}

void Display(struct List* list)
{
	list->cur = list->head;
	if (list->cur == NULL)
	{
		printf("연결리스트가 없습니다.\n");
	}
	else
	{
		while (list->cur->next != NULL)
		{
			printf("%d ->", list->cur->data);
			list->cur = list->cur->next;
		}
		//마지막노드에서 빠져나오기때문에 한 번더 출력
		printf("%d ->\n", list->cur->data);
	}
}

void main()
{
	struct List* list = (struct List*)malloc(sizeof(struct List));
	int select = 0;
	int num;//추가 받을 값
	int a;//삭제가 잘 되었느냐
	Initiailztion(list);

	while (select != 4)
	{
		printf("1)추가\n2)삭제\n3)출력\n4)종료\n입력 : ");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("값 입력 : ");
			scanf("%d", &num);
			LinkedInsert(list, num);
			break;
		case 2:
			printf("값 입력 : ");
			scanf("%d", &num);
			a = LinkedRemove(list, num);
			if (a == 1)
			{
				printf("잘제거 됨 \n");
			}
			break;
		case 3:
			Display(list);
			break;
		case 4:
			break;
		default:
			break;
		}
	}
}*/