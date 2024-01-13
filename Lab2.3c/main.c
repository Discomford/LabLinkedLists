﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "students.h"

int main()
{
	system("chcp 1251");
	system("cls");

	char path[] = "file";
	int action;
	struct NodeList* myList = NULL;
	while (1)
	{
		system("cls");
		printf("______________________________\n");
		printf("|1-                           |\n");
		printf("|2- Вывод списка              |\n");
		printf("|3- Добавление элемента списка|\n");
		printf("|4-                           |\n");
		printf("|5-                           |\n");
		printf("|6-                           |\n");
		printf("|7-                           |\n");
		printf("|8- Выход                     |\n");
		printf("______________________________\n");
		printf("Введите номер пункта меню:");
		scanf("%d", &action);

		switch (action)
		{
		case 1://Организация списка
			break;
		case 2://Просмотр списка
			printList(myList);
			break;
		case 3://Добавление элемента списка
			pushBack(&myList);
			break;
		case 4://Исключение элемента из списка
			break;
		case 5://Сохранение в файл
			break;
		case 6://Загрузка данных из файла
			break;
		case 7://Вставка двух новых элементов после первого элемента
			break;
		case 8://Выход из программы
			deleteList(myList);
			return 0;
			break;
		}
	}
}
