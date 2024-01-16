#ifndef STUDENTS_H

#include <stdio.h>

#define STUDENTS_H

struct Students
{
	int number;	    //Порядковый номер
	char name[30];  //Фамилия и инициалы
	int groupNumber;//Номер группы
	int mathMark;   //Оценка по математике
	int physicsMark;//Оценка по физике
	int englishMark;//Оценка по английскому языку
};

void printStudents(struct Students person);
struct Students writeStudents(int number);

#endif