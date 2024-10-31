#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 50

#define MAX 20

//int data[MAX];
//int front = -1;
//int rear = -1;
//
//int Queue_empty()
//{
//	if (front == rear)
//		return 1;
//	else
//		return 0;
//}
//
//int Queue_full()
//{
//	if (front == ((rear + 1) % MAX))
//		return 1;
//	else
//		return 0;
//}
//
//void Queue_enqueue(int item)
//{
//	if (Queue_full())
//	{
//		printf("빈 공간이 없습니다.\n");
//		return;
//	}
//	else
//	{
//		rear = (rear + 1) % MAX;
//		data[rear] = item;
//	}
//}
//
//int Queue_dequeue()
//{
//	if (Queue_empty())
//	{
//		printf("삭제할 것이 없습니다.\n");
//		return 0;
//	}
//	else
//	{
//		front = (front + 1) % MAX;
//		return data[front];
//	}
//}


typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;


//초기화
void init(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
	{
		g->adj_list[v] = NULL;
	}
}


//정점 삽입
void insert_vertex(GraphType* g)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		printf("overflow");
		return;
	}
	g->n++;
}

//간선 삽입		u = 정점	v = 정점에 연결된 정점
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


//출력
void print_adj_List(GraphType* g) {
	for (int i = 0; i < g->n; i++)
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


int visited[4] = { 0 };
//v는 시작, u는 현재
int Graph_dfs(GraphType* g, int v,int u) {
	GraphNode* w = g->adj_list[u];
	if (visited[u]) {//현재가 이미 방문되었다면
		if (v == u)//시작과 현재가 같다면 cycle
		{
			printf("사이클있음\n");
			return 1;
		}
		return 0;//같지 않으면 사이클 x
	}
	visited[u] = 1;
	//printf("%d\n", v);
	while (w != NULL)
	{
		int temp = w->vertex;
		printf("%d\n", temp);
		//if (visited[temp] == 0)
		//	Graph_dfs(g,temp);
		if (Graph_dfs(g, v, temp)) {
			return 1;
		}
		w = w->link;
	}
}

//void Graph_bfs(GraphType* g, int v) {
//	visited[v] = 1;
//	printf("%d ", v);
//	Queue_enqueue(v);
//	while (Queue_empty() != 1)
//	{
//		v = Queue_dequeue();
//		GraphNode* w = g->adj_list[v];
//		while (w != NULL)
//		{
//			if (visited[w->vertex] == 0)
//			{
//				visited[w->vertex] = 1;
//				printf("%d ", w->vertex);
//				Queue_enqueue(w->vertex);
//			}
//			w = w->link;
//		}
//	}
//}

//int main(void)
//{
//	GraphType* g;
//	g = (GraphType*)malloc(sizeof(GraphType));
//
//	init(g);
//	
//	for (int i = 0; i < 4; i++)
//		insert_vertex(g);
//	insert_edge(g, 0, 1);
//	insert_edge(g, 1, 2);
//	insert_edge(g, 1, 3);
//	insert_edge(g, 3, 0);
//
//	print_adj_List(g);
//
//
//	int a = Graph_dfs(g, 2, 2);
//	printf("%d", a);
//	//Graph_bfs(g, 0);
//	free(g);
//
//	return 0;
//
//}