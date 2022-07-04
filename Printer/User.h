#include <iostream>
#include "QueuePrint.h"
#pragma once
using namespace std;

class User
{
private:
	//friend class QueuePrint;
	int priority;
	string* docs;
	int maxNum;
	int docNum;	//переменная показывает: 1. номер документа в очереди печати принтера, 2. счетчик количества документов в очереди
public:
	User() {};
	User(int priority) {
		if (priority > 0 && priority <= 5) {
			this->priority = priority;		// приоритет должен быть от 1 до 5, где 1 - высший приоритет, а 5 - низший приоритет
			maxNum = 5;
			docNum = 0;
			docs = new string[maxNum];
		}
		else
		{
			cout << "Wrong input. Priority must be 1-5." << endl;
		}
		
	}

	//дружественная функция для добавленния документа пользователя в очередь принтера
	//friend bool QueuePrint::addPrintQueue(string &userDoc, int &usersPriority);

	bool isFull() {
		return docNum == maxNum;
	}

	//добавить документ в очередь печати пользователя и принтера
	void addUserQueue(string document) {
		if (!isFull()) {
			docs[docNum] = document;	//записываем строку в очередь печати пользователя
			// запускаем добавление документа в очередь принтера
			bool res = QueuePrint::addPrintQueue(&docs[docNum], &priority);
			// уведомляем пользователя о результате отработки функции добавления в очередь печати принтера
			if (res) {
				cout << "Doc is added to print queue." << endl;
				docNum++;	// увеличиваем значение docNum, чтобы реализовать функционал счетчика
			}
			else {
				cout << "Print queue if full. You can not print document now." << endl;
			}
		}
	}

	//удалить документ из очереди печати
	void deleteDoc (int docNumToDelete) {
		if (docNumToDelete-1 <= (docNum - 1)&&(docNumToDelete>0)) {
			cout << "Deleting doc N " << docNumToDelete << "...  ";
			for (int i = 0; i < docNum; i++) {
				if (i < docNumToDelete-1)	// пока i меньше индекса элемента для удаления - пропускаем
					continue;
				else if (i >= docNumToDelete-1) {	// если i равно или больше заданного индекса, то перезаписываем в текущую ячейку значение следующей ячейки
					docs[i] = docs[i + 1];
				}
			}
			cout << "Success." << endl;
			docNum--;	// уменьшаем счетчик элементов в массиве очереди
		}
		else {
			cout << "Wrong number!"<<endl;
			}
		}

	//очистка очереди печати
	void clearQueue() {	
		docNum = 0;
	}

	// количество документов в очереди (вернуть или вывести в консоль)
	int getQueueLength() {
		return docNum;
	}
	
	void printQueueLength() {
		cout << "There is " << docNum << " document in the queue." << endl;
	}

	// вывести все записи из очереди
	void printAll() {
		if (!isEmpty()) {
			for (int i = 0; i < docNum; i++) {
				cout << i+1<<".   " << docs[i]<< endl;
			}
		}
		else {
			cout << "Queue is empty." << endl;
		}
	}

	bool isEmpty() {
		return docNum == 0;
	}

	//извлечение первого документа из очереди пользователя
	string extract() {
		if (!isEmpty()) {
			string temp = docs[0];
			for (int i = 0; i < docNum; i++) {
				docs[i] = docs[i + 1];
			}
			docNum--;
			return temp;
		}
	}

	~User() {
		delete[] docs;
	}
};

