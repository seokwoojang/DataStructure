#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

/*typedef struct Node {
	int data;
	struct Node* next;
}Node;

//�ᵵ�ǰ� �Ƚᵵ��
struct List {
	Node* head;//�� ��
	Node* cur;//���� ���
	Node* be;//���� ���
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
	list->be = list->head;//���� ���
	list->cur = list->head;//���� ���
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
		printf("���Ḯ��Ʈ�� �����ϴ�.\n");
	}
	else
	{
		while (list->cur->next != NULL)
		{
			printf("%d ->", list->cur->data);
			list->cur = list->cur->next;
		}
		//��������忡�� ���������⶧���� �� ���� ���
		printf("%d ->\n", list->cur->data);
	}
}

void main()
{
	struct List* list = (struct List*)malloc(sizeof(struct List));
	int select = 0;
	int num;//�߰� ���� ��
	int a;//������ �� �Ǿ�����
	Initiailztion(list);

	while (select != 4)
	{
		printf("1)�߰�\n2)����\n3)���\n4)����\n�Է� : ");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("�� �Է� : ");
			scanf("%d", &num);
			LinkedInsert(list, num);
			break;
		case 2:
			printf("�� �Է� : ");
			scanf("%d", &num);
			a = LinkedRemove(list, num);
			if (a == 1)
			{
				printf("������ �� \n");
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