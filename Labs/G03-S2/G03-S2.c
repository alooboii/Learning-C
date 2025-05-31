#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* createNode(int value) {
	Node* new_node = (Node*)malloc(sizeof(Node));

	if(new_node == NULL) {
		return NULL;
	}

	new_node->data = value;
	new_node->next = NULL;
	return new_node;
}

void addNode(Node* head, Node* to_add) {
	Node* current = head;

	while(current->next != NULL) {
		current = current->next;
	}

	current->next = to_add;
}

int removeNode(Node* head, int target_value) {
	if (!head) return 0;
	Node* current = head;
	while (current->next && current->next->data != target_value) {
		current = current->next;
	}
	if (!current->next) return 0;
	Node* temp = current->next;
	current->next = current->next->next;
	free(temp);
	temp = NULL;
	return 1;
}

int count(Node* head, int searchFor) {
	int count = 0;
	if (!head) return count;
	Node* current = head;
	while (current) {
		if (current->data == searchFor) {
			count++;
		}
		current = current->next;
	}
	return count;
}

int evaluatePolynomial(Node* head, int x) {
	if (!head) return 0;
	int i = 0, result = 0;
	Node* current = head;
	while (current) {
		result += current->data * (pow(x,i++));
		current = current->next;
	}
	return result;
}

//---------------------------------------- TESTS ----------------------------------------------

int testRemove() {
	int marks = 0;
	Node* head = createNode(1);
	Node* node2 = createNode(2);
	Node* node3 = createNode(3);

	addNode(head, node2);
	addNode(head, node3);

	int result = removeNode(head, 2);

	if(result == 1 && head->next == node3) {
		marks += 4;
	}

	free(node3);
	free(head);

	printf(" %d/%d", marks, 4);

	return marks;
}

int testCount() {
	int marks = 0;

	// Test Case 1: Basic test with distinct values
    Node* head = createNode(1);
	Node* node2 = createNode(2);
	Node* node3 = createNode(3);
	addNode(head, node2);
	addNode(head, node3);

	int result1 = count(head, 2);
	if (result1 == 1) {
		marks += 2;
	}

	free(node3);
	free(node2);
	free(head);
	
	head = NULL;
	node2 = NULL;
	node3 = NULL;

	// Test Case 2: List contains multiple occurrences of the search value
	head = createNode(4);
	node2 = createNode(5);
	node3 = createNode(4);
	addNode(head, node2);
	addNode(head, node3);

	int result2 = count(head, 4);
	if (result2 == 2) {
		marks += 4;
	}

	free(node3);
	free(node2);
	free(head);
	
	head = NULL;
	node2 = NULL;
	node3 = NULL;

	// Test Case 3: List does not contain the search value
	head = createNode(6);
	node2 = createNode(7);
	node3 = createNode(8);
	addNode(head, node2);
	addNode(head, node3);

	int result3 = count(head, 9);
	if (result3 == 0) {
		marks += 2;
	}

	free(node3);
	free(node2);
	free(head);
	
	head = NULL;
	node2 = NULL;
	node3 = NULL;

	printf("%d/%d\n", marks, 8);
	return marks;
}

int testEvaluatePolynomial() {
	int marks = 0;

	// Test Case 1:
    Node* head = createNode(6);
	Node* node2 = createNode(2);
	Node* node3 = createNode(3);
	Node* node4 = createNode(1);
	
	addNode(head, node2);
	addNode(head, node3);
	addNode(head, node4);


	int result1 = evaluatePolynomial(head, 2);
	if (result1 == 30) {
		marks += 4;
	}
	
	free(node4);
	free(node3);
	free(node2);
	free(head);
	
	head = NULL;
	node2 = NULL;
	node3 = NULL;
	node4 = NULL;

	// Test Case 2:
	head = createNode(4);

	int result2 = evaluatePolynomial(head, 0);
	if (result2 == 4) {
		marks += 4;
	}
	
	free(head);
	head = NULL;

	printf("%d/%d\n", marks, 8);
	return marks;
}

int main() {
	printf("\033[1m\033[36m\nTesting Linked List:\033[0m");
	int total = 0;
	int max_marks = 20;

	printf("\n\n\033[35mTesting remove:\033[0m");
	total += testRemove();
	
	printf("\n\n\033[35mTesting count:\033[0m");
	total += testCount();
	
	printf("\n\n\033[35mTesting evaluate polynomial:\033[0m");
	total += testEvaluatePolynomial();

	printf("\n\n\033[1m\033[35mTotal:\033[0m %d/%d\n\n", total, max_marks);

	return 0;
}
