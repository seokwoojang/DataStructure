#include<stdio.h>
#include<stdlib.h>
#define Stack_size 7;


int ary[7];
int top=-1;
int item2 = 0;
int Stack_empty()
{
	if (top == -1)
		return 1;//True
	else {
		return 0;//False
	}
}

int Stack_full()
{
	if (top == 6)
	{
		return 1;
	}
	else
		return 0;
}

int Stack_push(int item)
{
	if (Stack_full())
		return 0;
	top = top + 1;
	ary[top] = item;
}

int Stack_pop()
{
	if (Stack_empty())
		return 0;
	item2 = ary[top];
	top = top - 1;
	return item2;
}

int main(void)
{
	Stack_push(1);
	Stack_push(2);
	Stack_push(3);
	Stack_push(4);
	Stack_push(5);
	printf("%d\n", Stack_pop());
	printf("%d\n", Stack_pop());
	printf("%d\n", Stack_pop());
	printf("%d\n", Stack_pop());
	printf("%d\n", Stack_pop());
}