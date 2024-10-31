/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 20

int left, right, pivot, low, high;

void print(int arr[]) {
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%3d", arr[i]);
	}
	printf("\n");
}

void Swap(int arr[], int x, int y) {
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void Bubble(int arr[]) {
	for (int i = MAX_SIZE - 1; i > 0; i--) {
		for (int a = 0; a < i; a++) {
			if (arr[a] > arr[a + 1]) {
				Swap(arr, a, a + 1);
			}
		}
		//print(arr);
	}
}

void Insert(int arr[]) {
	for (int i = 1; i < MAX_SIZE; i++) {
		int key = arr[i];
		int a = 0;
		
		for ( a = i - 1; a >= 0 && arr[a]>key; a--) {
			arr[a + 1] = arr[a];
		}
		arr[a + 1] = key;
		print(arr);
	}
}

int Quick_partition(int arr[], int left, int right) {
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (arr[high] > pivot)
			high = high - 1;
		while (low <= high && arr[low] <= pivot)
			low = low + 1;
		if (low <= high) {
			Swap(arr, low, high);
			low = low + 1;
			high = high - 1;
		}
	}
	Swap(arr, left, high);
	printf("pivot : %d\n", pivot);
	return high;
}

void Quick(int arr[], int left, int right) {
	int q;
	if (left < right) {
		q = Quick_partition(arr, left, right);
		Quick(arr, left, q - 1);
		Quick(arr, q + 1, right);
	}
}

void main() {
	int arr[MAX_SIZE], B[MAX_SIZE], I[MAX_SIZE], Q[MAX_SIZE];//원본 버블정렬 인설트 퀵정렬

	srand(time(NULL));

	for (int i = 0; i < MAX_SIZE; i++) {
		arr[i] = rand() % 20 + 1;
		B[i] = arr[i];
		I[i] = arr[i];
		Q[i] = arr[i];

		for (int a = 0; a < i; a++) {
			if (arr[a] == arr[i])//중복된 값 안들어가게끔 작업
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
	Quick(Q, 0, MAX_SIZE - 1);
	print(Q);
}*/