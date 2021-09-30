//Priority queue implementation
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

// percUp percolates a node up
void percUp(int arr[], int nodeIndex) {
	int parentIndex = (nodeIndex - 1) / 2;
	if (parentIndex < 0)
		return;
	if (arr[nodeIndex] > arr[parentIndex]) {
		swap(&arr[nodeIndex], &arr[parentIndex]);
		percUp(arr, parentIndex);
	}
}

// enqueue adds a node and heapifies
void enqueue(int arr[], int *sizeref, int capacity, int item) {
	if (*sizeref >= capacity)
		printf("Array full! \n");
	else {
		arr[*sizeref] = item;
		percUp(arr, *sizeref);
		*sizeref += 1;
	}
}

// dequeue removes a node
void dequeue(int arr[], int *sizeref) {
	if (*sizeref == 0) {
		printf("Queue empty!");
		return;
	}
	swap(&arr[0], &arr[*sizeref - 1]);
	*sizeref -= 1;
	percDown(arr, *sizeref, 0);
}

// printQueue prints the queue
void printQueue(int arr[], int size) {
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

// choose allows user to enq or deq
void choose(int arr[], int capacity, int *size) {
	int operation;
	int input;
	printf("Choose operation : ");
	scanf("%d", &operation);
	switch (operation) {
	case 1:
		printf("Enter value to enqueue : ");
		scanf("%d", &input);
		enqueue(arr, size, capacity, input);
		choose(arr, capacity, size);
		break;
	case 2:
		printf("Dequeuing...\n");
		dequeue(arr, size);
		choose(arr, capacity, size);
		break;
	case 0:
		printf("Priority Queue: ");
		printQueue(arr, *size);
		break;
	default:
		printf("Enter operation again");
		choose(arr, capacity, size);
	}
}

int main() {
	int arr[10];
	int capacity = 10;
	int size = 0;
	printf("Operations: ");
	printf("\n  Enqueue - 1");
	printf("\n  Dequeue - 2");
	printf("\n  Exit - 0 \n");

	choose(arr, capacity, &size);

	return 0;
}