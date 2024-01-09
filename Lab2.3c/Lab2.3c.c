#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//Структуры----------------------------------------------
struct Students		//Структура Students
{
	int number;	    //Порядковый номер
	char name[30];  //Фамилия и инициалы
	int groupNumber;//Номер группы
	int mathMark;   //Оценка по математике
	int physicsMark;//Оценка по физике
	int englishMark;//Оценка по английскому языку
};
struct NodeList		//Связанный список
{
	struct Students data;
	//int data;
    struct NodeList* next;
};
//Ввод структуры Students
struct Students writeStudents(int number)
{
	struct Students person;

	printf("\nПорядковый номер студента:%d\n", number);
	person.number = number;
	printf("Введите фамилию и инициалы студента:");
	scanf("%29s", &person.name);
	printf("Введите номер группы студента:");
	scanf("%d", &person.groupNumber);
	printf("Введите оценку по Математике студента:");
	scanf("%d", &person.mathMark);
	printf("Введите оценку по Физике студента:");
	scanf("%d", &person.physicsMark);
	printf("Введите оценку по Английскому языку студента:");
	scanf("%d", &person.englishMark);
	return person;
}


//-------------------------------------------------------
//1.Организация списка
struct NodeList* createNode()
{
	struct NodeList* head = (struct NodeList*)malloc(sizeof(struct NodeList));
	printf("Введите элемент списка:");
	scanf("%d", &head->data);
	head->next = NULL;
	return head;
}
//-------------------------------------------------------
//2.Вывод списка
void printList(struct NodeList *list)
{
	struct NodeList* temp = list;
	while (temp != NULL)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
	getchar();
	getchar();
}
//--------------------------------------------------------
//3.Добавление нового элемента в список
void pushBack(struct NodeList* list)
{
	struct NodeList* newNode = createNode();
	struct NodeList* temp = list;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}
//--------------------------------------------------------
//8.Удаление списка
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
//----------------Главная функция------------------------
int main()
{
	system("chcp 1251");
	system("cls");

	char path[] = "file";
	int action;
	struct NodeList* myList = NULL;
	while (1)
	{
		system("cls");
		printf("______________________________\n");
		printf("|1- Организация списка        |\n");
		printf("|2- Вывод списка              |\n");
		printf("|3- Добавление элемента списка|\n");
		printf("|4-                           |\n");
		printf("|5-                           |\n");
		printf("|6-                           |\n");
		printf("|7-                           |\n");
		printf("|8- Выход                     |\n");
		printf("______________________________\n");
		printf("Введите номер пункта меню:");
		scanf("%d", &action);

		switch (action)
		{
		case 1://Организация списка
			myList = createNode();
			break;
		case 2://Просмотр списка
			printList(myList);
			break;
		case 3://Добавление элемента списка
			pushBack(myList);
			break;
		case 4://Исключение элемента из списка
			break;
		case 5://Сохранение в файл
			break;
		case 6://Загрузка данных из файла
			break;
		case 7://Вставка двух новых элементов после первого элемента
			break;
		case 8://Выход из программы
			deleteList(myList);
			return 0;
			break;
		}
	}
}
