#include<stdio.h>

int random[10] = { 27,4,37,2,62,12,59,16,49,18 };

void swap(int left,int right) {
	int temp = random[left];
	random[left] = random[right];
	random[right] = temp;
}


int Quick_partition( int left, int right) {
	int low, high, pivot;
	low = left + 1;
	high = right;
	pivot = random[left];

	while (low <= high) {
		while (random[high] > pivot)
			high = high - 1;
		while(random[low] < pivot)
			low = low + 1;
		if (low <= high) {
			swap(low, high);
			low = low + 1;
			high = high - 1;
		}
	}
	swap(left,high);
	return high;
}

void Quick_sort(int left, int right) {
	int q;
	if (left < right) {
		q = Quick_partition(left, right);
		Quick_sort(left, q - 1);
		Quick_sort(q + 1, right);
	}
}

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", random[i]);
	}
	printf("\n");
	Quick_sort(0, 9);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", random[i]);
	}
	printf("\n");
}