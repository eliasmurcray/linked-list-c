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
	void *v = LinkedList_get(list, 1);
	if (v == NULL) {
		printf("NULL\n");
	} else {
		printf("%d\n", *(int *)v);
	}
	print_list(list);
	LinkedList_destroy(list);

	return 0;
}
