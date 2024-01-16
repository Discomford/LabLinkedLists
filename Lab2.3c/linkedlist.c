//Author: Daniyar Bayguzhinov
//������� ��� ������ � ����������� ���� NodeList

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

	if (*head == NULL)//���� ����������� ���� ������
	{
		*head = newNode;
	}
	else			  //���� ����������� ���� �� ������
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
		printf("\n���� ������ ����. ������� ���� �� 1 �������.\n");
		getchar();
		getchar();
		return;
	}
	struct NodeList* current = head;
	for (int i = 2; i < 4; i++)//���������� ���� ���������
	{
		struct NodeList* newNode = createNode();
		newNode->data = writeStudents(i);

		struct NodeList* savedNext = current->next;
		current->next = newNode;
		newNode->next = savedNext;
		current = current->next;
	}

	current = current->next;
	//��������� ����� ���������� �������
	while (current != NULL)
	{
		current->data.number += 2;
		current = current->next;
	}
	return;
}
//--------------------------------------------------------
//TODO 5.���������� � ����
void saveToFile(struct NodeList* head, char path[])
{
	;
}
//--------------------------------------------------------
//TODO 6.�������� ������ �� �����
void loadFromFile(struct NodeList** head)
{
	;
}
//--------------------------------------------------------
//TODO ������� �������� �������� 
void removeElement(struct NodeList** head, int number)
{
	struct NodeList* current;
	if(number < 1)//Exception
	{
		printf("\n������ ������� �� ����������");
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
				printf("\n������ ������� �� ����������");
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
	//��������� ����� ���������� �������
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

