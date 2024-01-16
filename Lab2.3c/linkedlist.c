//Author: Daniyar Bayguzhinov
//������� ��� ������ � ����������� ���� NodeList

#include "linkedlist.h"

//���������� ��������� �������
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
	changeThisAndSubsequentNumbers(current, 2);
}

struct NodeList* createNode()
{
	struct NodeList* node = (struct NodeList*)malloc(sizeof(struct NodeList));
	node->next = NULL;
	return node;
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

//������� �������� �������� 
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
			removeNextElem(current);
		}
		
	}
	changeThisAndSubsequentNumbers(current, -1);
	return;
}
//Private: �������� �������� �������� � ������ ���������
void removeNextElem(struct NodeList* current)
{
	struct NodeList* savedNext;
	savedNext = current->next->next;
	free(current->next);
	current->next = savedNext;
	current = current->next;
	return;
}
//Private: ��������� ������ ����� � ����������� ���������
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

