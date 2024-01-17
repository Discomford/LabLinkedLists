#ifndef MENU_H
//
#include <stdio.h>
#include <stdlib.h>
#include "students.h"
#include "linkedlist.h"

#define MENU_H

struct Students;
struct NodeList;


//Функции:
void menuAddElement(struct NodeList** list);
void menuRemoveStudentFromList(struct NodeList** list);
void menuLoadFromFile(struct NodeList** list, char path[]);
void menuAddTwoElementsAfterFirst(struct NodeList* list);

#endif