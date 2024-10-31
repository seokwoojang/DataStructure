#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* left_child;
	struct Node* right_child;
}Node;

void Preorder_traversal(Node* node)//전위순회
{
	if (node != NULL)
	{
		printf("%d", node->data);
		Preorder_traversal(node->left_child);
		Preorder_traversal(node->right_child);
	}
}

void Inorder_traversal(Node* node)//중위순회
{
	if (node != NULL)
	{
		Inorder_traversal(node->left_child);
		printf("%d", node->data);
		Inorder_traversal(node->right_child);
	}
}

void Postorder_traversal(Node* node)//후위순회
{
	if (node != NULL)
	{
		Postorder_traversal(node->left_child);
		Postorder_traversal(node->right_child);
		printf("%d", node->data);
	}
}

int Node_count(Node* node)
{
	int count = 0;
	if (node != NULL)
	{
		count = count + 1;
		Node_count(node->left_child);
		Node_count(node->right_child);
	}
	return count;
}

int Leaf_count(Node* node)
{
	int count = 0;
	if (node != NULL)
	{
		Leaf_count(node->left_child);
		if (node->left_child == NULL && node->right_child == NULL)
			count = count + 1;
		Leaf_count(node->right_child);
	}
	return count;
}