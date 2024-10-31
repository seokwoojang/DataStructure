#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* Left_child;
	struct Node* Right_child;
}Node;

Node* root = NULL;

int BST_min(Node* root)
{
	Node* temp = root;
	while (temp->Left_child != NULL)
		temp = temp->Left_child;
	return temp->data;
}

int BST_max(Node* root)
{
	Node* temp = root;
	while (temp->Right_child != NULL)
		temp = temp->Right_child;
	return temp->data;
}

Node* BST_search(Node* root, int key)
{
	while (root != NULL)
	{
		if (key == root->data)
			return root;
		if (key < root->data)
			root = root->Left_child;
		else
			root = root->Left_child;
	}
	return NULL;
}

Node* BST_insert(Node* root, int key)
{
	Node* parent = NULL;
	Node* node = root;
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = key;
	newnode->Left_child = NULL;
	newnode->Right_child = NULL;
	if (node == NULL)
	{
		root = newnode;
		root->Left_child = NULL;
		root->Right_child = NULL;
		return root;
	}
	while (node != NULL)
	{
		parent = node;
		if (key < node->data)
			node = node->Left_child;
		else
			node = node->Right_child;
	}
	if (key < parent->data)
		parent->Left_child = newnode;
	else
		parent->Right_child = newnode;
	/*else
	{
		if (root->data > key)
		{
			root->Left_child = BST_insert(root->Left_child, key);
		}
		else
		{
			root->Right_child = BST_insert(root->Right_child, key);
		}
	}*/
	return root;
}

Node* BST_delete(Node* root, int key)
{
	Node* child;
	Node* successor;
	Node* cur = root;
	Node* parent = NULL;
	while (cur != NULL && cur->data != key) {
		parent = cur;
		if (key < cur->data)
			cur = cur->Left_child;
		else
			cur = cur->Right_child;
	}
	//key���� �߰ߵ��� ����.
	if (cur == NULL)
		return root;
	//���1 ������尡 �ܸ� ���
	if ((cur->Left_child == NULL) && (cur->Right_child == NULL))
	{
		if (cur != root)//������ ���� ��Ʈ����� ��츦 �˻�, �� ��尡 �� ���� �����ϴ��� �˻� 
		{
			if (parent->Left_child == cur)
				parent->Left_child = NULL;
			else
				parent->Right_child = NULL;
		}
		else
		{
			root = NULL;
		}
		free(cur);
	}
	//���2 ������尡 �� ���� �ڽĳ�带 ������ ���
	else if ((cur->Left_child == NULL) || (cur->Right_child == NULL))
	{
		if (cur->Left_child == NULL)
			child = cur->Right_child;
		else
			child = cur->Left_child;

		if (cur != root) //�ܹ��� ���Ḯ��Ʈ�� ���� ����̶� �����.
		{
			if (cur == parent->Left_child)
				parent->Left_child = child;
			else
				parent->Right_child = child;
		}
		else
		{
			root = child;
		}
		free(cur);
	}
	//���3 ������尡 �� ���� �ڽĳ�带 ������ ���
	else
	{
		int k_value;
		successor = cur->Right_child;
		while (successor->Left_child != NULL)
		{
			successor = successor->Left_child;
		}
		k_value = successor->data;
		BST_delete(root, successor->data);
		cur->data = k_value;
	}
	return root;
}


void BST_print(Node* root)
{
	if (root == NULL)
		return;

	printf("%d ", root->data);
	BST_print(root->Left_child);
	BST_print(root->Right_child);
}

void main(void)
{
	root = BST_insert(root, 50);
	root = BST_insert(root, 35);
	root = BST_insert(root, 70);
	root = BST_insert(root, 6);
	root = BST_insert(root, 40);
	root = BST_insert(root, 45);
	root = BST_insert(root, 37);

	root = BST_delete(root, 35);

	BST_print(root);
}