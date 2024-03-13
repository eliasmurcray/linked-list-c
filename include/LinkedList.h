#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	void *value;
	struct Node *next;
} Node;

Node *Node_create(void *value);

typedef struct {
	Node *head;
} LinkedList;

LinkedList *LinkedList_create(Node *node);

void LinkedList_destroy(LinkedList *list);

void *LinkedList_get(LinkedList *list, int index);

void LinkedList_insert(LinkedList *list, int index, void *value);

void LinkedList_remove(LinkedList *list, int index);

void LinkedList_append(LinkedList *list, void *value);

#endif
