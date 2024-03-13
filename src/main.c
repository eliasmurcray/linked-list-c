#include "LinkedList.h"
#include <stdio.h>

void print_list(LinkedList *list) {
	if (list->head == NULL) {
		printf("List is empty");
	}

	node_t *n = list->head;
	while (n->next != NULL) {
		if (n->value == NULL) {
			printf("NULL -> ");
		} else {
			printf("%d -> ", *(int *)n->value);
		}
		n = n->next;
	}
	if (n->value == NULL) {
		printf("NULL\n");
	} else {
		printf("%d\n", *(int *)n->value);
	}
}

int main() {
	node_t *n = Node_create(&(int){4});
	LinkedList *list = LinkedList_create(n);
	LinkedList_append(list, NULL);
	LinkedList_append(list, &(int){10});
	print_list(list);
	void *v = LinkedList_get(list, 1);
	if (v == NULL) {
		printf("Value at index 1: NULL\n");
	} else {
		printf("Value at index 1: %d\n", *(int *)v);
	}
	LinkedList_insert(list, 5, &(int){20});
	print_list(list);
	LinkedList_insert(list, 1, &(int){20});
	print_list(list);
	LinkedList_insert(list, -1, &(int){15});
	LinkedList_destroy(list);

	return 0;
}
