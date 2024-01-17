//Author: Daniyar Bayguzhinov
//������� ��� ������ � ����������� NodeList

#include "linkedlist.h"

//���������� ��������� �������
void changeThisAndSubsequentNumbers	(struct NodeList* current, int value);
void removeNextElem					(struct NodeList* current);
struct NodeList* createNode();

int findListLength(struct NodeList* head)
{
	if (head == NULL)
		return 0;
	return 1 + findListLength(head->next);
}

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

void pushBack(struct NodeList** head, struct Students student)
{
	struct NodeList* newNode = createNode();
	newNode->data = student;

	if (*head == NULL)//���� ����������� ���� ������
	{
		*head = newNode;
	}
	else			  //���� ����������� ���� �� ������
	{
		struct NodeList* current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
	return;
}

void pushTwoElemAfterFirst(struct NodeList* head, struct Students first, struct Students second)
{
	if (head == NULL)
	{
		printf("\n���� ������ ����. ������� ���� �� 1 �������.\n");
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
	current->next = savedNext;
}
//Private
struct NodeList* createNode()
{
	struct NodeList* node = (struct NodeList*)malloc(sizeof(struct NodeList));
	node->next = NULL;
	return node;
}
//--------------------------------------------------------
//���������� � ����
void saveToFile(struct NodeList* head, char path[])
{
	struct NodeList* current = head;
	FILE* fp = fopen(path, "wb");
	if (!fp)
	{
		printf("�� ������� ������� ����\n");
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
// �������� ������ �� �����
void loadFromFile(struct NodeList** head, char path[])
{
	deleteList(*head);
	struct NodeList* current = head;
	struct Students  temp;
	int				 numbers = 1;
	
	FILE* fp = fopen(path, "rb");
	if (!fp)
	{
		printf("�� ������� ������� ����\n");
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

//������� �������� �������� 
void removeElement(struct NodeList** head, int number)
{
	struct NodeList* current;
	if(number < 1)//Exception
	{
		printf("\n������ ������� �� ����������");
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
				printf("\n������ ������� �� ����������");
				getchar(); getchar();
				return;
			}
			current = current->next;
		}
		removeNextElem(current);
		changeThisAndSubsequentNumbers(current, -1);
	}
	return;
}
//Private: �������� �������� �������� � ������ ���������
void removeNextElem(struct NodeList* current)
{
	struct NodeList* savedNext;
	savedNext = current->next->next;
	free(current->next);
	current->next = savedNext;
	return;
}
//Private: ��������� ������ ����� � ����������� ���������
void changeThisAndSubsequentNumbers(struct NodeList* current,int value)
{
	while (current != NULL)
	{
		current->data.number += value;
		current = current->next;
	}
	return;	
}
void changeItAndNextAfterNumbers(struct NodeList* head, int number, int value)
{
	for (int i = 0; i < number; i++)
	{
		head = head->next;
	}
	while (head != NULL)
	{
		head->data.number += value;
		head = head->next;
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

