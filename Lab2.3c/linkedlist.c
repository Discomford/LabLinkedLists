//Author: Daniyar Bayguzhinov
//Функции для работы с структурами типа NodeList

#include "linkedlist.h"

//Декларация приватных функций
void changeThisAndSubsequentNumbers	(struct NodeList* current, int value);
void removeNextElem					(struct NodeList* current);

void printList(struct NodeList* list)
{
	struct NodeList* temp = list;
	while (temp != NULL)
	{
		printStudents(temp->data);
		temp = temp->next;
	}
	getchar(); getchar();
	return;
}

void pushBack(struct NodeList** head, struct Students person)
{
	int number = 1;
	struct NodeList* newNode = createNode();

	if (*head == NULL)//Если добавленный узел первый
	{
		*head = newNode;
	}
	else			  //Если добавленный узел НЕ первый
	{
		struct NodeList* current = *head;
		while (current != NULL)
		{
			current = current->next;
			number++;
		}
		current = newNode;
	}
	person.number = number;
	newNode->data = person;
	return;
}

void pushTwoElemAfterFirst(struct NodeList* head, struct Students first, struct Students second)
{
	if (head == NULL)
	{
		printf("\nЭтот список пуст. Добавте хотя бы 1 элемент.\n");
		getchar(); getchar();
		return;
	}

	struct NodeList* current = head;
	struct NodeList* savedNext = current->next;

	current->next = createNode();
	current->next->data = first;

	current = current->next;
	current->next = createNode();
	current->next->data = second;
	
	current = current->next;
	current = current->next;
	changeThisAndSubsequentNumbers(current, 2);
}

struct NodeList* createNode()
{
	struct NodeList* node = (struct NodeList*)malloc(sizeof(struct NodeList));
	node->next = NULL;
	return node;
}
//--------------------------------------------------------
//Сохранение в файл
void saveToFile(struct NodeList* head, char path[])
{
	struct NodeList* current = head;
	FILE* fp = fopen(path, "wb");
	if (!fp)
	{
		printf("Не удалось открыть файл\n");
		getchar();getchar();
		return;
	}
	while (current != NULL)
	{
		fwrite(&current->data, sizeof(struct Students), 1, fp);
		current = current->next;
	}
	fclose(fp);
	getchar();getchar();
	return;
}
// Загрузка данных из файла
void loadFromFile(struct NodeList** head, char path[])
{
	deleteList(*head);
	struct NodeList* current = head;
	struct Students  temp;
	int				 numbers = 1;
	
	FILE* fp = fopen(path, "rb");
	if (!fp)
	{
		printf("Не удалось открыть файл\n");
		getchar(); getchar();
		return;
	}
	while (fread(&temp, sizeof(struct Students), 1, fp) == 1)
	{
		pushBack(head, temp);
	}

	fclose(fp);
	getchar(); getchar();
	return;
}

//Функция удаления элемента 
void removeElement(struct NodeList** head, int number)
{
	struct NodeList* current;
	if(number < 1)//Exception
	{
		printf("\nТакого объекта не существует");
		getchar(); getchar();
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
				getchar(); getchar();
				return;
			}
			current = current->next;
			removeNextElem(current);
			changeThisAndSubsequentNumbers(current, -1);
		}
	}
	return;
}
//Private: Удаление элемента стоящего в списке слудеющим
void removeNextElem(struct NodeList* current)
{
	struct NodeList* savedNext;
	savedNext = current->next->next;
	free(current->next);
	current->next = savedNext;
	return;
}
//Private: Изменения номера этого и последующих элементов
void changeThisAndSubsequentNumbers(struct NodeList* current,int value)
{
	while (current != NULL)
	{
		current->data.number += value;
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
	return;
}

