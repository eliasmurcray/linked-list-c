#include "LinkedList.h"

Node *Node_create(void *value) {
	Node *n = (Node *)malloc(sizeof(Node));

	if (n == NULL) {
		printf("Memory allocation failed for Node");
		exit(EXIT_FAILURE);
	}

	n->value = value;
	n->next = NULL;

	return n;
}

LinkedList *LinkedList_create(Node *node) {
	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));

	if (list == NULL) {
		printf("Memory allocation failed for LinkedList");
		exit(EXIT_FAILURE);
	}

	list->head = node;

	return list;
}

void LinkedList_destroy(LinkedList *list) {
	if (list->head == NULL)
		return;
	Node *n = list->head;
	while (n->next != NULL) {
		Node *tn = n;
		n = n->next;
		free(tn);
	}
	free(n);
	free(list);
}

void *LinkedList_get(LinkedList *list, int index) {
	if (list->head == NULL || index < 0)
		return NULL;
	if (index == 0)
		return list->head->value;
	Node *n = list->head;
	while (n->next != NULL && index > 0) {
		index--;
		n = n->next;
	}
	return n->value;
}

void LinkedList_append(LinkedList *list, void *value) {
	Node *new_node = Node_create(value);
	if (list->head == NULL) {
		list->head = new_node;
		return;
	}

	Node *n = list->head;
	while (n->next != NULL)
		n = n->next;
	n->next = new_node;
}

void LinkedList_insert(LinkedList *list, int index, void *value) {
	if (!list || index < 0) {
		fprintf(stderr, "Error: Invalid input\n");
		return;
	}

	Node *new_node = Node_create(value);
	if (index == 0) {
		new_node->next = list->head;
		list->head = new_node;
		return;
	}

	Node *n = list->head;
	while (n && --index > 0)
		n = n->next;
	if (!n) {
		fprintf(stderr, "Error: Index out of range\n");
		free(n);
		return;
	}

	new_node->next = n->next;
	n->next = new_node;
}

void LinkedList_remove(LinkedList *list, int index) {
	if (index < 0) {
		fprintf(stderr,
			"Failed to remove node: index %d out of range\n",
			index);
		return;
	}
	Node *n = list->head;
	if (n == NULL) {
		fprintf(stderr, "Failed to remove node: list empty");
		return;
	}
	const int original_index = index;
	while (n->next != NULL && --index != 0)
		n = n->next;
	if (index != 0) {
		fprintf(stderr,
			"Failed to remove node: index %d out of range\n",
			original_index);
		return;
	}
}
