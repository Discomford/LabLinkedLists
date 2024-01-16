//Author: Daniyar Bayguzhinov
//������� ��� ������ � ����������� ���� Students
#define _CRT_SECURE_NO_WARNINGS
#include "students.h"


//����� �������� Students
void printStudents(struct Students person)
{
	printf("_____________________________________________________________________\n");
	printf("|���������� ����� ��������:           |%-29d|\n", person.number);
	printf("|������� � �������� ��������:         |%-29s|\n", person.name);
	printf("|����� ������ ��������:               |%-29d|\n", person.groupNumber);
	printf("|������ �� ���������� ��������:       |%-29d|\n", person.mathMark);
	printf("|������ �� ������ ��������:           |%-29d|\n", person.physicsMark);
	printf("|������ �� ����������� ����� ��������:|%-29d|\n", person.englishMark);
	printf("_____________________________________________________________________\n");
}
//���� ��������� Students
struct Students writeStudents(int number)
{
	struct Students person;

	printf("\n���������� ����� ��������:\t\t\t%d\n", number);
	person.number = number;
	printf("������� ������� � �������� ��������:\t\t");
	scanf("%29s", &person.name);
	printf("������� ����� ������ ��������:\t\t\t");
	scanf("%d", &person.groupNumber);
	printf("������� ������ �� ���������� ��������:\t\t");
	scanf("%d", &person.mathMark);
	printf("������� ������ �� ������ ��������:\t\t");
	scanf("%d", &person.physicsMark);
	printf("������� ������ �� ����������� ����� ��������:\t");
	scanf("%d", &person.englishMark);
	return person;
}