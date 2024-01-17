//Author: Daniyar Bayguzhinov
//Модуль работы в меню

#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"


void menuAddElement(struct NodeList** list)
{
	struct Students newStudent = writeStudents(1 + findListLength(*list));
	pushBack(list, newStudent);
}
void menuRemoveStudentFromList(struct Students **list)
{
	int number;
	printf("\nВведите номер удаляемого студента:");
	scanf("%d", &number);
	removeElement(list, number);
	changeItAndNextAfterNumbers(*list, number - 1, -1);
	return;
}

void menuAddTwoElementsAfterFirst(struct NodeList* list)
{
	struct Students first	=	writeStudents(2);
	struct Students second	=	writeStudents(3);
	pushTwoElemAfterFirst(list, first, second);
	changeItAndNextAfterNumbers(list, 3, 2);
	return;
}