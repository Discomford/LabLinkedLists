#ifndef STUDENTS_H
#define STUDENTS_H

#include "students.h"
struct Students
{
	int number;	    //���������� �����
	char name[30];  //������� � ��������
	int groupNumber;//����� ������
	int mathMark;   //������ �� ����������
	int physicsMark;//������ �� ������
	int englishMark;//������ �� ����������� �����
};

void printStudents(struct Students person);
struct Students writeStudents(int number);

#endif