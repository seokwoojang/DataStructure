#include<stdio.h>
#include<stdlib.h>
/*
#define MAX_VERTICES 50

//�������
typedef struct GraphType {
	int n;//������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;


//�׷��� �ʱ�ȭ
void init(GraphType* g) {
	int i, j;
	g->n = 0;
	for (i = 0; i < MAX_VERTICES; i++){
		for (j = 0; j < MAX_VERTICES; j++) {
			g->adj_mat[i][j] = 0;
		}
	}
}


//���� ����
void insert_vertex(GraphType* g) {
	if (((g->n) + 1) > MAX_VERTICES) {
		printf("overflow");
		return;
	}
	g->n++;
}


//���� ����
void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {//������ ������ ������ ��(start, end)�� ū�� �˻�
		printf("key err");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

//��� �Լ�
void print_adj_mat(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%2d", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}


//�� ������ ���� ���
void adj_degree(GraphType* g) {
	for (int i = 0; i < g->n; i++)
	{
		int degree = 0;
		for (int j = 0; j < g->n; j++) {
			degree = degree + g->adj_mat[i][j];
		}
		printf("%d�� ���� : %d\n", i, degree);
	}
}



void main1234()
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 4; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_mat(g);
	adj_degree(g);

	free(g);
}*/