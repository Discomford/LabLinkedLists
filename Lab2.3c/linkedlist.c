//Author: Daniyar Bayguzhinov
//Функции для работы с структурами типа NodeList

#include "linkedlist.h"

struct NodeList* createNode()
{
	struct NodeList* node = (struct NodeList*)malloc(sizeof(struct NodeList));
	node->next = NULL;
	return node;
}

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
	while (current != NULL)
	{
		current->data.number += 2;
		current = current->next;
	}
	return;
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
//--------------------------------------------------------
//TODO Функция удаления элемента 
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
		struct NodeList* savedNext;
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
		}
		savedNext = current->next->next;
		free(current->next);
		current->next = savedNext;
		current = current->next;
	}
	//Привоение новых порядковых номеров
	while (current != NULL)
	{
		current->data.number -= 1;
		current = current->next;
	}
	return;
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
}

