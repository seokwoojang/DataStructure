/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)
#define MAX_LEN 50

typedef struct Stack {
	char stack[MAX_LEN];
	int top;
}Stack;

typedef struct Queue {
	char queue[MAX_LEN];
	int front, rear;
}Queue;

void push(Stack* stack, char s) {
	if (stack->top == MAX_LEN - 1)
		return;
	else {
		stack->top = stack->top + 1;
		stack->stack[stack->top] = s;
	}
}

void enqueue(Queue* queue, char s) {
	if ((queue->rear + 1) % MAX_LEN == queue->front) {
		return;
	}
	else
	{
		queue->rear = (queue->rear + 1) % MAX_LEN;
		queue->queue[queue->rear] = s;
	}
}

char pop(Stack* stack) {
	if (stack->top == -1) {
		return 'x';
	}
	else
	{
		char temp = stack->stack[stack->top];
		stack->top = stack->top - 1;
		return temp;
	}
}

char dequeue(Queue* queue) {
	if (queue->front == queue->rear) {
		return 'x';
	}
	else {
		queue->front = (queue->front + 1) % MAX_LEN;
		char temp = queue->queue[queue->front];
		return temp;
	}
}

int match(Stack* stack, Queue* queue) {
	for (int i = 0; i < strlen(stack->stack); i++) {
		char a = pop(stack);
		char b = dequeue(queue);
		if (a != b) {
			return 0;
		}
	}
	return 1;
}

void main(void) {
	char input[MAX_LEN];
	scanf("%s", input);

	Stack stack;
	stack.top = -1;

	Queue queue;
	queue.front = 0;
	queue.rear = 0;

	for (int i = 0; i < strlen(input); i++) {
		push(&stack,input[i]);
		enqueue(&queue,input[i]);
	}

	if (match(&stack, &queue)) {
		printf("È¸¹®");
	}
	else
	{
		printf("x");
	}
}*/