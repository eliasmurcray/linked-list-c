#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	void *value;
	struct Node *next;
} node_t;

node_t *Node_create(void *value);

typedef struct {
	node_t *head;
} LinkedList;

LinkedList *LinkedList_create(node_t *node);

void LinkedList_destroy(LinkedList *list);

void *LinkedList_get(LinkedList *list, int index);

void LinkedList_insert(LinkedList *list, int index, void *value);

void LinkedList_remove(LinkedList *list, int index);

void LinkedList_append(LinkedList *list, void *value);

#endif
