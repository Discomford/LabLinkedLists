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
void pushBack		(struct NodeList** head, struct Students person);
void pushTwoElemAfterFirst(struct NodeList* head, struct Students first, struct Students second);//Не работатет
void saveToFile		(struct NodeList* head, char path[]);
void loadFromFile	(struct NodeList** head, char path[]);//Не работатет
void removeElement	(struct NodeList** head, int number);
void deleteList		(struct NodeList* list);

#endif