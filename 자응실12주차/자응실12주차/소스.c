#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 9

typedef struct Node {
	int data;
	struct Node* L;
	struct Node* R;
}Node;

Node* Creat(int number) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = number;
	newnode->L = NULL;
	newnode->R = NULL;

	return newnode;
}

void Preorder(Node* current) {
	if (current == NULL)
		return;
	printf("%d -> ", current->data);
	Preorder(current->L);
	Preorder(current->R);
}

void Inorder(Node* current) {
	if (current == NULL)
		return;
	Inorder(current->L);
	printf("%d -> ", current->data);
	Inorder(current->R);
}

void Postorder(Node* current) {
	if (current == NULL)
		return;
	Postorder(current->L);
	Postorder(current->R);
	printf("%d -> ", current->data);
}

void main(void)
{
	srand(time(NULL));

	Node* tree[MAX_SIZE],*root,*current;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		tree[i] = Creat(i);
	}

	root = tree[0];
	
	for (int i = 1; i < MAX_SIZE; i++)
	{
		int flag = 1;
		current = root;

		while (flag) {
			switch (rand()%2)
			{
			case 0:
				if (current->L != NULL)
				{
					current = current->L;
				}
				else
				{
					current->L = tree[i];
					flag = 0;
				}
				break;
			case 1:
				if (current->R != NULL)
				{
					current = current->R;
				}
				else
				{
					current->R = tree[i];
					flag = 0;
				}
				break;
			default:
				break;
			}
		}
	}

	printf("전위 : ");
	Preorder(root);
	printf("\n");

	printf("중위 : ");
	Inorder(root);
	printf("\n");

	printf("후위 : ");
	Postorder(root);
	printf("\n");
}