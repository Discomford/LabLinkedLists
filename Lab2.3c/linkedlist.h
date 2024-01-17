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

struct NodeList* createNode	();
int	 findListLength			(struct NodeList* head);
struct Students getByNumber	(struct NodeList* head,		int number);
void printList				(struct NodeList* list);
void pushBack				(struct NodeList** head,	struct Students person);
void pushTwoElemAfterFirst	(struct NodeList* head,		struct Students first, struct Students second);
int	 changeItAndNextAfterNumbers(struct NodeList* head, int number, int value);
void saveToFile				(struct NodeList* head,		char path[]);
void loadFromFile			(struct NodeList** head,	char path[]);
int	 removeElement			(struct NodeList** head,	int number);
void deleteList				(struct NodeList* list);

#endif