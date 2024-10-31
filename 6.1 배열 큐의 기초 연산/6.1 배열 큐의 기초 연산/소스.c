#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 20

int data[MAX];
int front = -1;
int rear = -1;

int Queue_empty()
{
	if (front == rear)
		return 1;
	else
		return 0;
}

int Queue_full()
{
	if (front == ((rear + 1) % MAX))
		return 1;
	else
		return 0;
}

void Queue_enqueue(int item)
{
	if (Queue_full())
	{
		printf("빈 공간이 없습니다.\n");
		return;
	}
	else
	{
		rear = (rear + 1) % MAX;
		data[rear] = item;
	}
}

char Queue_dequeue()
{
	if (Queue_empty())
	{
		printf("삭제할 것이 없습니다.\n");
		return 0;
	}
	else
	{
		front = (front + 1) % MAX;
		return data[front];
	}
}

int Prefix_eval(int prefix_exp[])
{
	for (int i = 0; i < 13; i++)
	{
		Queue_enqueue(prefix_exp[i]);
	}
	int queue_len = rear - front;
	while (queue_len != 1)
	{
		char op1, op2;
		int result;
		char token = Queue_dequeue();
		switch (token)
		{
		case '+': case'-': case'*': case'/':
			op1 = data[front + 1];
			op2 = data[front + 2];
			if (op1 && op2)
			{
				Queue_dequeue();
				Queue_dequeue();
				switch (token)
				{
				case'+':
					result = (int)op1 + (int)op2;
					break;
				case'-':
					result = (int)op1 - (int)op2;
					break;
				case'*':
					result = (int)op1 * (int)op2;
					break;
				case'/':
					result = (int)op1 / (int)op2;
					break;
				}

			}
			else
			{
				Queue_enqueue(token);
			}
			break;
		default:
			Queue_enqueue(token);
			break;
		}
		if (rear > front)
		{
			queue_len = rear - front;
		}
		else
		{
			queue_len = (MAX - front - 1) + (rear + 1);
		}
	}
	int final_value = Queue_dequeue();
	return final_value;
}

int main(void)
{
	char ex[] = "-+*0+28*+4863";
	int x[13] = { '-','+','*',9,'+',2,8,'*','+',4,8,6,3};
	
}