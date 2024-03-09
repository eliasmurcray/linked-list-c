#include "LinkedList.h"
#include <stdio.h>

void print_list(LinkedList *list) {
	if (list->head == NULL) {
		printf("List is empty");
	}

	printf("{");

	node_t *n = list->head;
	while (n->next != NULL) {
		if (n->value == NULL) {
			printf(" , ");
		} else {
			printf("%d, ", *(int *)n->value);
		}
		n = n->next;
	}
	if (n->value == NULL) {
		printf(" }\n");
	} else {
		printf("%d}\n", *(int *)n->value);
	}
}

int main() {
	node_t *n = Node_create(&(int){4});
	LinkedList *list = LinkedList_create(n);
	list->head->next = Node_create(NULL);
	void *v = LinkedList_get(list, 0);
	printf("%d\n", *(int *)v);
	print_list(list);
	LinkedList_destroy(list);

	return 0;
}
