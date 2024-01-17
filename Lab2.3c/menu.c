//Author: Daniyar Bayguzhinov
//������ ������ � ����

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
	
	printf("\n�������� �� ����� ������ �������");
}
void menuRemoveStudentFromList(struct NodeList **list)
{
	int number, accept;
	printf("\n������� ����� ���������� ��������:");
	scanf("%d", &number);

	printStudents(getByNumber(*list, number-1));
	printf("\n�� ������� ��� ������ ������� ������� ��������?(1/0)");

	scanf("%d", &accept);
	if (accept)
	{
		removeElement(list, number);
		changeItAndNextAfterNumbers(*list, number - 1, -1);
		printf("\n������� ��� ������� ������!");
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