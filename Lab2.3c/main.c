//Author: Daniyar Bayguzhinov
//Главный файл исходного кода
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"



int main()
{
	system("chcp 1251");
	system("cls");

	char	path[] = "file";
	int		action;
	struct	NodeList* myList = NULL;
	while (1)
	{
		system("cls");
		printf("_______________________________________\n");
		printf("|1-                                     |\n");
		printf("|2- Вывод списка                        |\n");
		printf("|3- Добавление элемента списка          |\n");
		printf("|4- Загрузка из файла                   |\n");
		printf("|5- Сохранение в файл                   |\n");
		printf("|6- Удаление элемента                   |\n");
		printf("|7- Вставка двух элементов после первого|\n");
		printf("|8- Выход                               |\n");
		printf("_______________________________________\n");
		printf("Введите номер пункта меню:");
		scanf("%d", &action);
		mainMenu(action, myList, path);
		
	}
}
