#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
}node;

node* list_create(int* ary, int n) {
	node* head = NULL;
	for (int i = 0; i < n; i++)
	{
		node* newNode = (node*)malloc(sizeof(node));
		newNode->data = ary[i];
		newNode->link = head;
		head = newNode;
	}
	return head;
}

node* list_insert(node* head, int item, int p)
{
	node* temp = head;
	for (int i = 0; i < p - 1; i++)
	{
		temp = temp->link;
	}
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = item;
	newNode->link = temp->link;
	temp->link = newNode;
	return head;
}

node* list_delete(node* head, int item) {
	if (head == NULL)
		return NULL;
	
	node* previous = head;
	node* removed = head;
	
	int count = 0;

	while (removed != NULL)
	{
		count = count + 1;
		if (removed->data == item) {
			break;
		}
		previous = removed;
		removed = removed->link;
	}
	
	if (count == 1) {
		head = head->link;
	}
	else {
		
		previous->link = removed->link;
	
	}

	free(removed);

	if (previous->link == NULL)
	{
		return NULL;
	}
	else {
		return head;
	}
}

//특정 노드를 찾아라
node* getnodeAt(node* head, int index) {
	node* horse = head;
	int count = 0;

	while (horse != NULL) {
		if (count == index) {
			return horse;
		}
		count++;
		horse = horse->link;
	}

	return NULL;
}

int main(void)
{
	int ary[3] = { 10,20,30 };
	int n = 3;
	node* head = NULL;
	head = list_create(ary, n);

	//현재 위치
	node* cur = NULL;
	//출력
	printf("---------------------------------------------create----------\n");
	for (int i = 0; i < n; i++)
	{
		cur = getnodeAt(head, i);
		printf("%d번째 노드 : %d\n",i+1, cur->data);
	}

	int item = 40;
	//첫 번째 자리 뒤에 추가
	head = list_insert(head, item, 1);
	printf("---------------------------------------------insert----------\n");
	for (int i = 0; i < n + 1; i++)
	{
		cur = getnodeAt(head, i);
		printf("%d번째 노드 : %d\n", i + 1, cur->data);
	}
	

	head = list_delete(head,20);
	printf("---------------------------------------------delete-----------\n");
	for (int i = 0; i < n; i++)
	{
		cur = getnodeAt(head, i);
		printf("%d번째 노드 : %d\n", i + 1, cur->data);
	}
}