#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "linkedlist.h"
#include "students.h"

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
void removeElement	(struct NodeList* head, int number);
void deleteList		(struct NodeList* list);

#endif