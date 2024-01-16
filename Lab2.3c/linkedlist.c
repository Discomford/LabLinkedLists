//Author: Daniyar Bayguzhinov
//Функции для работы с структурами типа NodeList

#include "linkedlist.h"

//Декларация приватных функций
int changeThisAndSubsequentNumbers(struct NodeList* current, int value);
void removeNextElem(struct NodeList* current);

void printList(struct NodeList* list)
{
	struct NodeList* temp = list;
	while (temp != NULL)
	{
		printStudents(temp->data);
		temp = temp->next;
	}
	getchar();
	getchar();
	return;
}

void pushBack(struct NodeList** head)
{
	int number = 1;
	struct NodeList* newNode = createNode();

	if (*head == NULL)//Если добавленный узел первый
	{
		*head = newNode;
	}
	else			  //Если добавленный узел НЕ первый
	{
		struct NodeList* temp = *head;
		number++;
		while (temp->next != NULL)
		{
			temp = temp->next;
			number++;
		}
		temp->next = newNode;
	}
	newNode->data = writeStudents(number);
}

void pushTwoElemAfterFirst(struct NodeList* head)
{
	if (head == NULL)
	{
		printf("\nЭтот список пуст. Добавте хотя бы 1 элемент.\n");
		getchar();
		getchar();
		return;
	}
	struct NodeList* current = head;
	for (int i = 2; i < 4; i++)//Добавление двух элементов
	{
		struct NodeList* newNode = createNode();
		newNode->data = writeStudents(i);

		struct NodeList* savedNext = current->next;
		current->next = newNode;
		newNode->next = savedNext;
		current = current->next;
	}

	current = current->next;
	//Привоение новых порядковых номеров
	changeThisAndSubsequentNumbers(current, 2);
}

struct NodeList* createNode()
{
	struct NodeList* node = (struct NodeList*)malloc(sizeof(struct NodeList));
	node->next = NULL;
	return node;
}
//--------------------------------------------------------
//TODO 5.Сохранение в файл
void saveToFile(struct NodeList* head, char path[])
{
	;
}
//--------------------------------------------------------
//TODO 6.Загрузка данных из файла
void loadFromFile(struct NodeList** head)
{
	;
}

//Функция удаления элемента 
void removeElement(struct NodeList** head, int number)
{
	struct NodeList* current;
	if(number < 1)//Exception
	{
		printf("\nТакого объекта не существует");
		getchar();
		getchar();
		return;
	}
	else if (number == 1)
	{
		current = (*head)->next;
		free(*head);
		*head = current;
	}
	else
	{
		current = *head;
		for (int i = 0; i<number - 2; i++)
		{
			if (current->next == NULL)//Exception
			{
				printf("\nТакого объекта не существует");
				getchar();
				getchar();
				return;
			}
			current = current->next;
			removeNextElem(current);
		}
		
	}
	changeThisAndSubsequentNumbers(current, -1);
	return;
}
//Private: Удаление элемента стоящего в списке слудеющим
void removeNextElem(struct NodeList* current)
{
	struct NodeList* savedNext;
	savedNext = current->next->next;
	free(current->next);
	current->next = savedNext;
	current = current->next;
	return;
}
//Private: Изменения номера этого и последующих элементов
int changeThisAndSubsequentNumbers(struct NodeList* current,int value)
{
	while (current != NULL)
	{
		current->data.number += value;
		current = current->next;
	}
	return 0;	
}

void deleteList(struct NodeList* list)
{
	struct NodeList* temp;
	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	return;
}

