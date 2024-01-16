//Author: Asan Asanov
//Модуль работы в меню

#include "menu.h"
#define _CRT_SECURE_NO_WARNINGS

//TODO Просмотр всего списка
//TODO Добавление элемента в список+
//TODO Исключение из списка по номеру
//TODO Сохранение в файл
//TODO Загрузка из файла-
//TODO Вставка двух новых элементов после первого элемента-
//TODO Выход из программы с удалением списка из памяти

int menu(int action, struct NodeList list, char path[])
{
	switch (action)
	{
	case 1:
		break;
	case 2://Просмотр списка
		
		break;
	case 3://Добавление элемента списка
		break;
	case 4://Исключение элемента из списка
		break;
	case 5://Сохранение в файл
		break;
	case 6://
		break;
	case 7://Вставка двух новых элементов после первого элемента
		break;
	case 8://Выход из программы
		return 0;
		break;
	}
}