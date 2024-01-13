#define _CRT_SECURE_NO_WARNINGS
#include "students.h"
//Вывод стуктуры Students
void printStudents(struct Students person)
{
	printf("_____________________________________________________________________\n");
	printf("|Порядковый номер студента:           |%-29d|\n", person.number);
	printf("|Фамилия и инициалы студента:         |%-29s|\n", person.name);
	printf("|Номер группы студента:               |%-29d|\n", person.groupNumber);
	printf("|Оценка по Математике студента:       |%-29d|\n", person.mathMark);
	printf("|Оценка по Физике студента:           |%-29d|\n", person.physicsMark);
	printf("|Оценка по Английскому языку студента:|%-29d|\n", person.englishMark);
	printf("_____________________________________________________________________\n");
}
//Ввод структуры Students
struct Students writeStudents(int number)
{
	struct Students person;

	printf("\nПорядковый номер студента:%d\n", number);
	person.number = number;
	printf("Введите фамилию и инициалы студента:");
	scanf("%29s", &person.name);
	printf("Введите номер группы студента:");
	scanf("%d", &person.groupNumber);
	printf("Введите оценку по Математике студента:");
	scanf("%d", &person.mathMark);
	printf("Введите оценку по Физике студента:");
	scanf("%d", &person.physicsMark);
	printf("Введите оценку по Английскому языку студента:");
	scanf("%d", &person.englishMark);
	return person;
}