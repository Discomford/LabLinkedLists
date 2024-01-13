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

	printf("\n���������� ����� ��������:%d\n", number);
	person.number = number;
	printf("������� ������� � �������� ��������:");
	scanf("%29s", &person.name);
	printf("������� ����� ������ ��������:");
	scanf("%d", &person.groupNumber);
	printf("������� ������ �� ���������� ��������:");
	scanf("%d", &person.mathMark);
	printf("������� ������ �� ������ ��������:");
	scanf("%d", &person.physicsMark);
	printf("������� ������ �� ����������� ����� ��������:");
	scanf("%d", &person.englishMark);
	return person;
}