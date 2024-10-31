#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

typedef struct node {
	int data;
	struct node* prev; //���� ��带 ����Ŵ
	struct node* next; //���� ��带 ����Ŵ
}Node;

typedef struct list {
	Node* head;
	Node* cur;
}List;


//�ʱ�ȭ
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
		printf("����Ʈ�� �����ϴ�.\n");
		return;
	}
	else
	{
		while (list->cur != NULL)
		{
			if (list->cur->data == data)
			{
				if (list->cur == list->head)//ù ��° ��� ����
				{
					list->head = list->head->next;
					list->head->prev = NULL;
				}
				else if (list->cur->next == NULL)//��������� ����
				{
					list->cur->prev->next = NULL;
				}
				else//�߰���� ����
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
		printf("ã�� ���� �����ϴ�.\n");
	}
}

void Display(List* list)
{
	if (list->head == NULL)
	{
		printf("����Ʈ�� �����ϴ�.\n");
		return;
	}
	else
	{
		list->cur = list->head;

		printf("������ ���� : \n");
		while (list->cur->next != NULL)
		{
			printf("%d ->", list->cur->data);
			list->cur = list->cur->next;
		}
		printf("%d \n", list->cur->data);

		printf("���� ���� : \n");
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
		printf("1)�߰�\n2)����\n3)���\n4)����\n-------------\n");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			printf("�� �Է� : ");
			scanf("%d", &data);
			Insert(&list, data);
			Display(&list);
			break;
		case 2:
			printf("�� �Է� : ");
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