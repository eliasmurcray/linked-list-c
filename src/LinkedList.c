#include "LinkedList.h"

node_t *Node_create(void *value) {
	node_t *n = (node_t *)malloc(sizeof(node_t));

	if (n == NULL) {
		printf("Memory allocation failed for node_t");
		exit(EXIT_FAILURE);
	}

	n->value = value;
	n->next = NULL;

	return n;
}

LinkedList *LinkedList_create(node_t *node) {
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
	node_t *n = list->head;
	while (n->next != NULL) {
		node_t *tn = n;
		n = n->next;
		free(tn);
	}
	free(n);
	free(list);
}

void *LinkedList_get(LinkedList *list, int index) {
	if (list->head == NULL || index < 0)
		return NULL;
	if (index == 0) return list->head->value;
	node_t *n = list->head;
	while (n->next != NULL && index > 0) {
		index--;
		n = n->next;
	}
	return n->value;
}

void LinkedList_append(LinkedList *list, void *value) {
	node_t *new_node = Node_create(value);
	if (list->head == NULL) {
		list->head = new_node;
		return;
	}

	node_t *n = list->head;
	while (n->next != NULL) n = n->next;
	n->next = new_node;
}

void LinkedList_insert(LinkedList *list, int index, void *value) {
	node_t *new_node = Node_create(value);
	if (index < 0) {
		fprintf(stderr, "Failed to insert node: index %d out of range\n", index);
		return;
	}
	node_t *n = list->head;
	if (n == NULL) {
		list->head = new_node;
		return;
	}
	const int original_index = index;
	while (n->next != NULL && --index != 0) n = n->next;
	if (index != 0) {
		fprintf(stderr, "Failed to insert node: index %d out of range\n", original_index);
		return;
	}
	new_node->next = n->next;
	n->next = new_node;
}
