#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define Max 20

void print(int arr[]) {
	for (int i = 0; i < Max; i++) {
		printf("%3d", arr[i]);
	}
	printf("\n");
}

void swap(int arr[], int x, int y) {
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void Bubble(int arr[]) {
	for (int i = Max - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr, j, j + 1);
			}
		}
	}
}

void Insert(int arr[]) {
	for (int i = 1; i < Max; i++) {
		int temp = arr[i];
		int j=0;
		for (j = i - 1; j >= 0 && arr[j]>temp; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}

int partition(int arr[], int left, int right) {
	int high, pivot, low;
	pivot = arr[left];
	low = left + 1;
	high = right;

	while (low <= high) {
		while (arr[high] > pivot)
			high = high - 1;
		while (arr[low] < pivot&&low<=right)
			low = low + 1;
		if (low <= high)
		{
			swap(arr, low, high);
		}
	}
	if (low > high) {
		swap(arr, high, left);
	}
	return high;
}

void Quick(int arr[], int left, int right) {
	if (left < right) {
		int q = partition(arr, left, right);
		Quick(arr, left, q - 1);
		Quick(arr, q + 1, right);
	}
	
}

void main() {
	int arr[Max], B[Max], I[Max], Q[Max];

	srand(time(NULL));

	for (int i = 0; i < Max; i++) {
		arr[i] = rand() % 20 + 1;
		B[i] = arr[i];
		I[i] = arr[i];
		Q[i] = arr[i];

		for (int a = 0; a < i; a++) {
			if (arr[a] == arr[i])
			{
				i--;
				break;
			}
		}
	}

	printf("-------원본------------\n");
	print(arr);

	printf("------버블------------\n");
	Bubble(B);
	print(B);

	printf("------삽입정렬------------\n");
	Insert(I);
	print(I);
	
	printf("------퀵 정렬------------\n");
	Quick(Q, 0, Max - 1);
	print(Q);
}