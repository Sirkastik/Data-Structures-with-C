//Queue Implementation with a Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int value;
	struct Node *next;
};

// enqueue appends a node
void enqueue(struct Node** ref, int value) {
	if (*ref != NULL)
		enqueue (&(*ref)->next, value);
	else {
		struct Node* newNode = malloc(sizeof(struct Node));
		newNode->value = value;
		newNode->next = (*ref);
		(*ref) = newNode;
	}
	return;
}


// dequeue deletes first node
void dequeue(struct Node** headref) {
	if (*headref == NULL) {
		printf("Queue empty!\n");
		return;
	}
	printf("Dequeuing... \n");
	struct Node* ptr = *headref;
	*headref = (*headref)->next;
	free(ptr);
	return;
}

// peek prints the first node on the list
void peek(struct Node* head) {
	if (head == NULL) {
		printf("Queue empty!\n");
		return;
	}
	printf("First value: %d \n", head->value);
	return;
}

// Prints the Queue
void printQueue(struct Node* node) {
    while (node != NULL) {
    	printf("%d - > ", node->value);
    	node = node->next;
    }
    printf("\n");
    return;
}

// choose allows user to enq or deq
void choose (struct Node** headref) {
	int operation;
	int input;
	printf("Choose operation : ");
	scanf("%d", &operation);
	switch (operation) {
		case 1: //peek
			peek(*headref);
			choose(headref);
			break;
		case 2 : //enqueue
			printf("Enter value to enqueue : ");
			scanf("%d", &input);
			enqueue(&(*headref), input);
			choose(headref);
			break;
		case 3 : //dequeue
			dequeue(headref);
			choose(headref);
			break;
		case 0 : //exit & print
			printf("Queue : ");
			printQueue(*headref);
			break;
		default :
			printf("Wrong input!\n");
			choose(headref);
	}
	return;
}


int main() {
	struct Node* head = NULL;

	printf("Operations: ");
	printf("\n  Peek - 1");
	printf("\n  Enqueue - 2");
	printf("\n  Dequeue - 3");
	printf("\n  Exit - 0 \n");
	
	choose(&head);
	
	return 0;
}