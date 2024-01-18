//Author: Daniyar Bayguzhinov
//Функции для работы с структурами NodeList

#include "linkedlist.h"

//Декларация приватных функций
struct NodeList*	createNodeWithData	(struct Students data);
struct NodeList*	createNode			();
void				removeFirstElement	(struct NodeList** head);
void				removeNextElem		(struct NodeList* current);

//Поиск длины списка
int findListLength(struct NodeList* head)
{
	if (head == NULL) return 0;
	return 1 + findListLength(head->next);
}
//Получить элемент по номеру
struct Students getByNumber(struct NodeList* head, int number)
{
	struct NodeList* current = head;
	for (int i = 0; i < number; i++)
	{
		current = current->next;
	}
	return current->data;
}
//Вывод последовательно всех данных из списка
void printList(struct NodeList* list)
{
	struct NodeList* current = list;
	while (current != NULL)
	{
		printStudents(current->data);
		current = current->next;
	}
	getchar(); getchar();
	return;
}
//Добавление элемента в конец списка
void pushBack(struct NodeList** head, struct Students student)
{
	if (*head == NULL)//Если добавленный узел первый
	{
		*head = createNodeWithData(student);
	}
	else			  //Если добавленный узел НЕ первый
	{
		struct NodeList* current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = createNodeWithData(student);
	}
	return;
}
//Добавление двух элементов после первого в список
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

	current->next = createNodeWithData(first);
	current = current->next;
	
	current->next = createNodeWithData(second);
	current = current->next;
	
	current->next = savedNext;
}
//Private: создание узла c данными
struct NodeList* createNodeWithData(struct Students data)
{
	struct NodeList* node = createNode();
	node->data = data;
	return node;
}
//Private: создание пустого узла
struct NodeList* createNode()
{
	struct NodeList* node = (struct NodeList*)malloc(sizeof(struct NodeList));
	node->next = NULL;
	return node;
}
//Сохранение в файл
void saveToFile(struct NodeList* head, char path[])
{
	struct NodeList* current = head;
	FILE* fp = fopen(path, "wb");
	if (!fp)//Exception
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
	struct Students  temp;
	
	FILE* fp = fopen(path, "rb");
	if (!fp)//Exception
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
int removeElement(struct NodeList** head, int number)
{
	struct NodeList* current;
	if ((number < 1) || ((*head) == NULL))//Exception
	{
		printf("\nТакого объекта не существует");
		getchar(); getchar();
		return 1;
	}
	else if (number == 1)
	{
		removeFirstElement(head);
		return 0;
	}

	current = *head;
	for (int i = 0; i<number - 2; i++)
	{
		if (current->next == NULL)//Exception
		{
			printf("\nТакого объекта не существует");
			getchar(); getchar();
			return 1;
		}
		current = current->next;
	}
	removeNextElem(current);
	return 0;
}
//Private: Удаление первого элемента в списке
void removeFirstElement(struct NodeList** head)
{
	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
		return;
	}
	struct NodeList* newHead = (*head)->next;
	free(*head);
	*head = newHead;
	return;
}
//Private: Удаление элемента стоящего в списке слудующим
void removeNextElem(struct NodeList* current)
{
	struct NodeList* savedNext = current->next->next;
	free(current->next);
	current->next = savedNext;
	return;
}
//Функция смены номеров этого и последующих элементов на значение value
int changeItAndNextAfterNumbers(struct NodeList* head, int number, int value)
{
	for (int i = 0; i < number; i++)
	{
		if (head == NULL) return 1;//Exception
		head = head->next;
	}
	while (head != NULL)
	{
		head->data.number += value;
		head = head->next;
	}
	return 0;
}
//Удаление списка с отчищением памяти
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