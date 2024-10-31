#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int ary[11] = { 0 };

void Max_heap_insert(int key, int h_size)
{
	int index;
	h_size = h_size + 1;
	index = h_size;
	ary[index] = key;
	while ((index != 1) && key > ary[index / 2])
	{
		ary[index] = ary[index / 2];
		index = index / 2;
	}
	ary[index] = key;
}

int Max_heap_delete(int h_size)
{
	int delete_key = ary[1];
	int temp = ary[h_size];
	h_size = h_size - 1;
	int parent = 1;
	int index = 2;
	while (index <= h_size) {
		if (ary[index] < ary[index + 1])
		{
			index = index + 1;
		}
		if (temp < ary[index])
		{
			ary[parent] = ary[index];
			parent = index;
			index = index * 2;
		}
	}
	ary[parent] = temp;
	return delete_key;
}

void main(void)
{
	srand(time(NULL));

	printf("무작위 값 10개\n");
	for (int i = 1; i <= 10; i++)
	{
		int n = rand()% 101;
		Max_heap_insert(n, i-1);
		printf("%d ", n);
	}
	printf("\n\n");
	printf("트리 삽입 후\n");
	for (int i = 1; i <= 10; i++)
	{
		printf("%d ", ary[i]);
	}
	printf("\n\n");
	printf("트리 삭제 후\n");
	for (int i = 1; i <= 10; i++)
	{
		printf("%d ", Max_heap_delete(11-i));
	}
}