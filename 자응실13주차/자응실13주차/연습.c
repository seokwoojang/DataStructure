#include<stdio.h>
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
	if (tree->root == NULL) {
		tree->root = newnode;
		return;
	}
	Node* cur = tree->root;
	Node* parent=NULL;
	while (cur != NULL) {
		parent = cur;
		if (cur->key > data)
			cur = cur->L;
		else
			cur = cur->R;
	}
	if (parent->key > data) {
		parent->L = newnode;
	}
	else
		parent->R = newnode;
}

void del(Tree* tree,int data) {
	Node* cur = tree->root;
	Node* parent= NULL;
	while ((cur != NULL) &&(cur->key != data)) {
		parent = cur;
		if (cur->key > data)
			cur = cur->L;
		else
			cur = cur->R;
	}
	if (cur == NULL)
		return;
	if ((cur->L == NULL) && (cur->R == NULL)) {
		if (cur == tree->root) {
			tree->root = NULL;
		}
		else {
			if (parent->L == cur)
				parent->L = NULL;
			else
				parent->R = NULL;
		}
		free(cur);
	}
	else if (cur->L == NULL || cur->R == NULL) {
		Node* child=NULL;
		if (cur->L == NULL)
			child = cur->R;
		else
			child = cur->L;
		if (cur == tree->root) {
			tree->root = child;
		}
		else {
			if (parent->L == cur)
				parent->L = child;
			else
				parent->R = child;
		}
		free(cur);
	}
	else {
		Node* temp = cur->R;
		while(temp->L != NULL) {
			temp = temp->L;
		}
		int key = temp->key;
		del(tree, key);
		cur->key = key;
	}
}

void display(Node* cur) {
	if (cur != NULL) {
		display(cur->L);
		printf("%d ", cur->key);
		display(cur->R);
	}
}

void main() {
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
	display(tree.root);

	printf("\n\n");
	del(&tree, 7);
	display(tree.root);

	printf("\n\n");
	del(&tree, 5);

	display(tree.root);
}