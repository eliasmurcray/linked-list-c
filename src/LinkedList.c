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

void *LinkedList_get(LinkedList *list, size_t index) {
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
