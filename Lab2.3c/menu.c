//Author: Daniyar Bayguzhinov
//Модуль работы в меню

#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"

void menuAddElement(struct NodeList** list)
{
	struct Students newStudent = writeStudents(1 + findListLength(*list));
	pushBack(list, newStudent);
}

void menuLoadFromFile(struct NodeList** list, char path[])
{
	int length = findListLength(*list);
	loadFromFile(list, path);
	changeItAndNextAfterNumbers(*list, length, length);
	
	printf("\nЗагрузка из файла прошла успешно");
}
void menuRemoveStudentFromList(struct NodeList **list)
{
	int number, accept;
	printf("\nВведите номер удаляемого студента:");
	scanf("%d", &number);

	printStudents(getByNumber(*list, number-1));
	printf("\nВы уверены что хотите удалить данного студента?(1/0)");

	scanf("%d", &accept);
	if (accept)
	{
		removeElement(list, number);
		changeItAndNextAfterNumbers(*list, number - 1, -1);
		printf("\nСтудент был успешно удален!");
		getchar(); getchar();
	}
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