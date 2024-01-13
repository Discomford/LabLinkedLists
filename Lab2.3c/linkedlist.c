#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>
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

//--------------------------------------------------------
//TODO 5.���������� � ����
//--------------------------------------------------------
//TODO 6.�������� ������ �� �����
//--------------------------------------------------------

void removeElement(struct NodeList* head, int number)
{
	;
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

