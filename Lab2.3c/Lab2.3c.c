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
    struct NodeList* next;
};
//Вывод стуктуры Students
void printStudents(struct Students person)
{
	printf("_____________________________________________________________________\n");
	printf("|Порядковый номер студента:           |%-29d|\n", person.number);
	printf("|Фамилия и инициалы студента:         |%-29s|\n", person.name);
	printf("|Номер группы студента:               |%-29d|\n", person.groupNumber);
	printf("|Оценка по Математике студента:       |%-29d|\n", person.mathMark);
	printf("|Оценка по Физике студента:           |%-29d|\n", person.physicsMark);
	printf("|Оценка по Английскому языку студента:|%-29d|\n", person.englishMark);
	printf("_____________________________________________________________________\n");
}
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
	struct NodeList* node = (struct NodeList*)malloc(sizeof(struct NodeList));
	node->next = NULL;
	return node;
}
//-------------------------------------------------------
//2.Вывод списка
void printList(struct NodeList *list)
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
//--------------------------------------------------------
//3.Добавление нового элемента в список
void pushBack(struct NodeList** head)
{
	int number = 1;
	struct NodeList* newNode = createNode();

	if (*head == NULL)//Если добавленный узел первый
	{
		*head = newNode;
	}
	else//Если добавленный узел НЕ первый
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
//TODO 4.Исключение элемента из списка
void remove(struct NodeList* head, int number)
//--------------------------------------------------------
//TODO 5.Сохранение в файл
//--------------------------------------------------------
//TODO 6.Загрузка данных из файла
//--------------------------------------------------------
//TODO Функция которая добавляет в непустой список два элемента после первого
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
			break;
		case 2://Просмотр списка
			printList(myList);
			break;
		case 3://Добавление элемента списка
			pushBack(&myList);
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
