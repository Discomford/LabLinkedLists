#ifndef LINKEDLIST_H
//
#include <stdio.h>
#include <stdlib.h>
#include "students.h"

#define LINKEDLIST_H

struct Students;

struct NodeList
{
	struct Students data;
	struct NodeList* next;
};

struct NodeList* createNode();
void printList		(struct NodeList* list);
void pushBack		(struct NodeList** head);
void pushTwoElemAfterFirst(struct NodeList* head);
void removeElement	(struct NodeList** head, int number);
void deleteList		(struct NodeList* list);

#endif