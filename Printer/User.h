#include <iostream>
#pragma once
using namespace std;

class User
{
private:
	int priority;
	string* docs;
	int maxNum=5;
	int docNum=0;	//переменная показывает: 1. номер документа в очереди! печати данного пользователя, 2. счетчик количества документов в очереди
public:
//User() {};
	User(int priority) : priority{ priority }, docs{ new string [maxNum]}{}

	//добавить документ в очередь печати
	void add(string document) {
		//if (!isFull()) {
		docs[docNum++] = document;	//записываем строку в очередь, после чего увеличиваем значение docNum, чтобы реализовать функционал счетчика
		cout << "Doc is added to print queue." << endl;
	}
		/*else {
			cout << "Queue is full. Try again later." << endl;
		}
	}*/

	//удалить документ из очереди печати
	void deleteDoc (int docNumToDelete) {
		if (docNumToDelete <= (docNum - 1)&&(docNumToDelete>0)) {
			cout << "Deleting doc N " << docNumToDelete << endl;
			for (int i = 0; i < docNum; i++) {
				if (i < docNumToDelete)	// пока i меньше индекса элемента для удаления - пропускаем
					continue;
				else if (i >= docNumToDelete) {	// если i равно или больше заданного индекса, то перезаписываем в текущую ячейку значение следующей ячейки
					docs[i] = docs[i + 1];
				}
			}
			docNum--;	// уменьшаем счетчик элементов в массиве очереди
		}
		else {
			cout << "Wrong number!";
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
				cout << i<<".   " << docs[i]<< endl;
			}
		}
		else {
			cout << "Queue is empty." << endl;
		}
	}

	bool isEmpty() {
		return docNum == 0;
	}

	//bool isFull() {
	//	return docNum == maxNum;
	//}

	//очередь печати данного пользователя
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

