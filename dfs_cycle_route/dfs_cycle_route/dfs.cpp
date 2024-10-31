#include<cstdio>
#include<stdlib.h>
#define MAX_VERTICES 50

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

void init(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
	{
		g->adj_list[v] = NULL;
	}
}

void insert_vertex(GraphType* g)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		printf("overflow");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
	GraphNode* newnode;
	if (u >= g->n || v >= g->n) {
		printf("vertex index err");
		return;
	}
	newnode = (GraphNode*)malloc(sizeof(GraphNode));
	newnode->vertex = v;
	newnode->link = g->adj_list[u];
	g->adj_list[u] = newnode;
}

void print_adj_List(GraphType* g) {
	for (int i = 1; i < g->n; i++)
	{
		GraphNode* p = g->adj_list[i];
		printf("정점 %d의 인접 리스트", i);
		while (p != NULL)
		{
			printf("->%d", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

int r_stack[MAX_VERTICES] = { 0 };
int pre[MAX_VERTICES] = { 0 };
int mark[MAX_VERTICES] = { 0 };
int cyclenumber = 0;

void dfs_cycle(int u, int p, GraphType* graph) {
	if (r_stack[u] == 2)
		return;

	if (r_stack[u] == 1) {//백간선 발견
		cyclenumber++;
		int cur = p;
		mark[p] = cyclenumber;
		while (cur != u) {
			cur = pre[cur];
			mark[cur] = cyclenumber;
		}
		printf("경로 :");
		for (int i = 0; i < 9; i++) {
			if (mark[i] == cyclenumber)
				printf(" %d ->", i);
		}
		printf("\n");
		return;
	}
	pre[u] = p;
	r_stack[u] = 1;
	GraphNode* w = graph->adj_list[u];
	while (w != NULL) {
		if (w->vertex == pre[u]) {
			w = w->link;
			continue;
		}
		dfs_cycle(w->vertex, u, graph);
		w = w->link;
	}

	r_stack[u] = 2;
}

int main(void)
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));

	init(g);

	for (int i = 0; i < 7; i++)
		insert_vertex(g);
	/*insert_edge(g, 1, 2);
	insert_edge(g, 1, 3);
	insert_edge(g, 3, 4);
	insert_edge(g, 3, 5);
	insert_edge(g, 4, 1);
	insert_edge(g, 5, 6);
	insert_edge(g, 5, 7);
	insert_edge(g, 7, 8);
	insert_edge(g, 8, 5);*/

	insert_edge(g, 1, 2);
	insert_edge(g, 1, 3);
	insert_edge(g, 3, 4);
	insert_edge(g, 4, 1);
	insert_edge(g, 4, 6);
	insert_edge(g, 6, 3);

	print_adj_List(g);

	dfs_cycle(3, 0, g);

	if (cyclenumber > 0) {
		printf("사이클 수 : %d", cyclenumber);
	}

	free(g);

	return 0;

}