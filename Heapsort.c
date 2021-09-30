// Heapsort Algorithm that processes a non-heap array to a heap and sorts it
#include <stdio.h>

// swap swaps two elements
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// percDown percolates down
void percDown(int arr[], int size, int nodeIndex) {
	int largerChildIndex;
	int leftChildIndex = 2 * nodeIndex + 1;
	int rightChildIndex = 2 * nodeIndex + 2;
	//If node had children, find larger child
	if (leftChildIndex < size) {
		if (rightChildIndex < size) {
			if (arr[rightChildIndex] > arr[leftChildIndex])
				largerChildIndex = rightChildIndex;
			else
				largerChildIndex = leftChildIndex;
		}
		else
			largerChildIndex = leftChildIndex;
		//compare larger child and node
		if (arr[largerChildIndex] > arr[nodeIndex]) {
			//swap
			swap(&arr[nodeIndex], &arr[largerChildIndex]);
			//recursion
			if (2 * largerChildIndex + 1 < size)
				percDown(arr, size, largerChildIndex);
		}
	}
}

// heapify processes the array into a heap array
void heapify(int arr[], int size) {
	//starting from the last non-leaf node
	for (int i = size / 2 - 1; i >= 0; i--)
		percDown(arr, size, i);
}

// heapSort heapifies and sorts the array
void heapSort(int arr[], int size) {
	//heapify
	heapify(arr, size);
	//sort
	for (int i = size - 1; i >= 0; i--) {
		//swap root and leaf
		swap(&arr[0], &arr[i]);
		//percolate down
		percDown(arr, i, 0);
	}
}

// printArray prints the sorted array
void printArray(int arr[], int size) {
	for (int i = size - 1; i >= 0; --i)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {
	int arr[] = {10, 3, 76, 34, 23, 32, 47, 51, 69};
	int size = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, size);
	//print the array
	printf("The sorted array is: \n");
	printArray(arr, size);
	return 0;
}