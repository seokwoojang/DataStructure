#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

/*typedef struct node {
	int data;
	struct node* next;
}Node;

typedef struct list {
	Node* tail;//������
	Node* cur;//����
	Node* be;//���� ���
}List;


//�ʱ�ȭ
void Init(List* list)
{
	list->tail = NULL;
	list->cur = NULL;
	list->be = NULL;
}

//�� �տ� ����
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
		printf("����Ʈ�� �����ϴ�.\n");
		return;
	}
	list->cur = list->tail->next;//����
	list->be = list->tail;//����

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
		//���� ���� �ԷµǸ� Ż��
		if (list->be == list->tail)
			return;
	}
}

void Display(List* list)
{
	if (list->tail == NULL) {
		printf("����Ʈ�� �����ϴ�.\n");
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
*/