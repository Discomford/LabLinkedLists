//Author: Daniyar Bayguzhinov
//Главный файл исходного кода
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "menu.h"


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
		switch (action)
		{
		case 1:
			break;
		case 2://Просмотр списка
			printList(myList);
			break;
		case 3://Добавление элемента списка
			menuAddElement(&myList);
			break;
		case 4://Загрузка из файла
			menuLoadFromFile(&myList, path);
			break;
		case 5://Сохранение в файл
			saveToFile(myList, path);
			break;
		case 6://Удаление элемента 
			menuRemoveStudentFromList(&myList);
			break;
		case 7://Вставка двух новых элементов после первого элемента
			menuAddTwoElementsAfterFirst(myList);
			break;
		case 8://Выход из программы
			return 0;
			break;
		}	
	}
}
