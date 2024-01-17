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
		printf("________________________________________\n");
		printf("|1- Вывод списка                        |\n");
		printf("|2- Добавление элемента в список        |\n");
		printf("|3- Вставка двух элементов после первого|\n");
		printf("|4- Удаление элемента                   |\n");
		printf("|5- Сохранение в файл                   |\n");
		printf("|6- Загрузка из файла                   |\n");
		printf("|7- Выход                               |\n");
		printf("________________________________________\n");
		printf("Введите номер пункта меню:");
		scanf("%d", &action);
		switch (action)
		{
		case 1://Вывод списка
			printList(myList);
			break;
		case 2://Добавление элемента списка
			menuAddElement(&myList);
			break;
		case 3://Вставка двух новых элементов после первого элемента
			menuAddTwoElementsAfterFirst(myList);
			break;
		case 4://Удаление элемента 
			menuRemoveStudentFromList(&myList);
			break;
		case 5://Сохранение в файл
			menuSaveToFile(myList, path);
			break;
		case 6://Загрузка в файл
			menuLoadFromFile(&myList, path);
			break;
		case 7://Выход из программы
			return 0;
			break;
		}	
	}
}
