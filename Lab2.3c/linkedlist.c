//Author: Daniyar Bayguzhinov
//������� ��� ������ � ����������� NodeList

#include "linkedlist.h"

//���������� ��������� �������
struct NodeList*	createNodeWithData	(struct Students data);
struct NodeList*	createNode			();
void				removeFirstElement	(struct NodeList** head);
void				removeNextElem		(struct NodeList* current);

//����� ����� ������
int findListLength(struct NodeList* head)
{
	if (head == NULL) return 0;
	return 1 + findListLength(head->next);
}
//�������� ������� �� ������
struct Students getByNumber(struct NodeList* head, int number)
{
	struct NodeList* current = head;
	for (int i = 0; i < number; i++)
	{
		current = current->next;
	}
	return current->data;
}
//����� ��������������� ���� ������ �� ������
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
//���������� �������� � ����� ������
void pushBack(struct NodeList** head, struct Students student)
{
	if (*head == NULL)//���� ����������� ���� ������
	{
		*head = createNodeWithData(student);
	}
	else			  //���� ����������� ���� �� ������
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
//���������� ���� ��������� ����� ������� � ������
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

	current->next = createNodeWithData(first);
	current = current->next;
	
	current->next = createNodeWithData(second);
	current = current->next;
	
	current->next = savedNext;
}
//Private: �������� ���� c �������
struct NodeList* createNodeWithData(struct Students data)
{
	struct NodeList* node = createNode();
	node->data = data;
	return node;
}
//Private: �������� ������� ����
struct NodeList* createNode()
{
	struct NodeList* node = (struct NodeList*)malloc(sizeof(struct NodeList));
	node->next = NULL;
	return node;
}
//���������� � ����
void saveToFile(struct NodeList* head, char path[])
{
	struct NodeList* current = head;
	FILE* fp = fopen(path, "wb");
	if (!fp)//Exception
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
	struct Students  temp;
	
	FILE* fp = fopen(path, "rb");
	if (!fp)//Exception
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
int removeElement(struct NodeList** head, int number)
{
	struct NodeList* current;
	if ((number < 1) || ((*head) == NULL))//Exception
	{
		printf("\n������ ������� �� ����������");
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
			printf("\n������ ������� �� ����������");
			getchar(); getchar();
			return 1;
		}
		current = current->next;
	}
	removeNextElem(current);
	return 0;
}
//Private: �������� ������� �������� � ������
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
//Private: �������� �������� �������� � ������ ���������
void removeNextElem(struct NodeList* current)
{
	struct NodeList* savedNext = current->next->next;
	free(current->next);
	current->next = savedNext;
	return;
}
//������� ����� ������� ����� � ����������� ��������� �� �������� value
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
//�������� ������ � ���������� ������
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