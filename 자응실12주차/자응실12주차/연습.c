/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define Max 9

typedef struct Node {
	int data;
	struct Node* L;
	struct Node* R;
}Node;

Node* Creat(int num) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = num;
	newnode->L = NULL;
	newnode->R = NULL;

	return newnode;
}

void Preorder(Node* cur) {
	if (cur == NULL)
		return;
	printf("%d", cur->data);
	Preorder(cur->L);
	Preorder(cur->R);
}

void Inorder(Node* cur) {
	if (cur == NULL)
		return;
	Inorder(cur->L);
	printf("%d", cur->data);
	Inorder(cur->R);
}

void Postorder(Node* cur) {
	if (cur == NULL)
		return;
	Postorder(cur->L);
	Postorder(cur->R);
	printf("%d", cur->data);
}

void main(void) {
	srand(time(NULL));

	Node* tree[Max], * root, * cur;

	for (int i = 0; i < Max; i++) {
		tree[i] = Creat(i);
	}

	root = tree[0];

	for (int i = 1; i < Max; i++) {
		int flag = 1;
		cur = root;

		while (flag) {
			switch (rand()%2)
			{
			case 0:
				if (cur->L != NULL) {
					cur = cur->L;
				}
				else {
					cur->L = tree[i];
					flag = 0;
				}
				break;
			case 1:
				if (cur->R != NULL) {
					cur = cur->R;
				}
				else {
					cur->R = tree[i];
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
}*/