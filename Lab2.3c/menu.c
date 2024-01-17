//Author: Daniyar Bayguzhinov
//Модуль работы в меню

#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"

//Пункт меню, добавляющий элемент в список с сохранением нумерации
void menuAddElement(struct NodeList** list)
{
	struct Students newStudent = writeStudents(1 + findListLength(*list));
	pushBack(list, newStudent);
	return;
}
//Пункт меню, добавляющий два элемента после первого
void menuAddTwoElementsAfterFirst(struct NodeList* list)
{
	struct Students first = writeStudents(2);
	struct Students second = writeStudents(3);
	pushTwoElemAfterFirst(list, first, second);
	changeItAndNextAfterNumbers(list, 3, 2);
	return;
}
//Пункт меню, удаляющий студента из списка
void menuRemoveStudentFromList(struct NodeList** list)
{
	int number, accept;
	printf("\nВведите номер удаляемого студента:");
	scanf("%d", &number);

	printStudents(getByNumber(*list, number - 1));
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
//Пункт меню, сохраняющий данные в файл
void menuSaveToFile(struct NodeList* list, char path[])
{
	saveToFile(list, path);
	printf("\nДанные были успешно сохраненны!");
	return;
}
//Пункт меню, загружающий данные в файл
void menuLoadFromFile(struct NodeList** list, char path[])
{
	int length = findListLength(*list);
	loadFromFile(list, path);
	changeItAndNextAfterNumbers(*list, length, length);
	
	printf("\nЗагрузка из файла прошла успешно");
	return;
}

