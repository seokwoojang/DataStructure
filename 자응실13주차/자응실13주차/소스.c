/*#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int key;
	struct Node* L;
	struct Node* R;
}Node;

typedef struct tree {
	Node* root;
}Tree;

void Insert(Tree* tree, int data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->key = data;
	newnode->L = NULL;
	newnode->R = NULL;
	if (tree->root == NULL)
	{
		tree->root = newnode;
	}
	else
	{
		Node* cur = tree->root;
		Node* parent = NULL;
		while (cur != NULL)
		{
			parent = cur;
			if (cur->key == data)
			{
				printf("%d ���� �����ϰ� �ֽ��ϴ�.",data);
				return;
			}
			if (cur->key < data)
				cur = cur->R;
			else
				cur = cur->L;
		}
		if (parent->key < data)
			parent->R = newnode;
		else
			parent->L = newnode;
	}
}

void Delete(Tree* tree, int data)
{
	Node* temp;
	Node* parent = NULL;
	Node* child =NULL;
	Node* cur = tree->root;
	while ((cur != NULL)&& (cur->key != data))
	{
		parent = cur;
		if (cur->key < data)
			cur = cur->R;
		else
			cur = cur->L;
	}
	if (cur == NULL)
	{
		return;
	}
	//���1 �ܸ������ ���
	if ((cur->L == NULL) && (cur->R == NULL))
	{
		if (cur != tree->root)
		{
			if (parent->L == cur)
				parent->L = NULL;
			else
				parent->R = NULL;
		}
		else
		{
			tree->root = NULL;
		}
		free(cur);
	}
	//���2 �ڽ��� 1���ΰ��
	else if ((cur->L == NULL) || (cur->R == NULL))
	{
		if (cur->L == NULL)
			child = cur->R;
		else
			child = cur->L;
		if (cur != tree->root)
		{
			if (parent->L == cur)
			{
				parent->L = child;
			}
			else
				parent->R = child;
		}
		else
		{
			tree->root = child;
		}
		free(cur);
	}
	//���3 �ڽ��� 2���ΰ��
	else
	{
		temp = cur->R;
		while (temp->L != NULL)
		{
			temp = temp->L;
		}
		int k = temp->key;
		Delete(tree, k);
		cur->key = k;
	}
}

void Display(Node* cur)
{
	if (cur != NULL)
	{
		Display(cur->L);
		printf("%d -> ", cur->key);
		Display(cur->R);
	}
}

void main() 
{
	Tree tree;
	tree.root = NULL;

	Insert(&tree, 5);
	Insert(&tree, 3);
	Insert(&tree, 8);
	Insert(&tree, 6);
	Insert(&tree, 2);
	Insert(&tree, 4);
	Insert(&tree, 1);
	Insert(&tree, 9);
	Insert(&tree, 7);
	Display(tree.root);
	printf("\n\n");
	Delete(&tree, 7);

	Display(tree.root);
	printf("\n\n");
	Delete(&tree, 5);

	Display(tree.root);
	printf("\n\n");
	Delete(&tree, 6); Display(tree.root);
	printf("\n\n");

}*/