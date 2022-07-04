//#include "User.h"
#include <iostream>
#include <string.h>
#pragma once
using namespace std;

class QueuePrint
{
private:
	string* queuePrintDocs;	//очередь печати
	int length;	//длина очереди
	int maxLength;	//максимальная длина очереди
	int* pri;	//приоритет
	//friend class User;
public:
	QueuePrint() {
		maxLength = 20;
		length = 0;
		queuePrintDocs = new string[maxLength];
		pri = new int[maxLength];
	};

	~QueuePrint() {
		delete[] queuePrintDocs;
		delete[] pri;
	}

	//дружественная функция для доступа к первому документу в очереди пользователя
	//friend string User::extract();

	void clear() {
		length = 0;
	}

	bool isEmpty() {
		return length == 0;
	}

	bool isFull() {
		return length == maxLength;
	}

	// получить длину текущей очереди
	int getQueueLength() {
		return length;
	}

	//добавление документа пользователя в очередь (очередь с приоритетным включением)
	 bool addPrintQueue (string &userDoc, int &usersPriority) {
		 //если очередь пустая (нет документов), просто добавляем документ (сравнивать не с чем)
		 if (isEmpty) {
			 queuePrintDocs[length] = userDoc;
			 this->pri[length] = usersPriority;
			 length++;
			 return true;
		}
		 
		 //если очередь не заполнена до конца, то ищем место для документа согласно приоритету
		 else if (!isFull()) {
			 // (высший приоритет - 1, низший - 5)
			 //сравниваем приоритеты из очереди в входящим приоритетом
			 int pos = 0;	// текущая позиция
			 for (int i = 0; i < length; i++) {
				 if (pri[i] <= usersPriority) {
					 continue;
				 }
				 // находим место для вставки документа в очередь (текущий документ в очереди имеет приоритет ниже входящего)
				 else {
					 pos = i;	//сохраняем позицию для вставки документа
					 int tempLength = length + 1;	// определяем будущую длину очереди
					 for (tempLength; tempLength>i; tempLength-- ) {
						 queuePrintDocs[tempLength] = queuePrintDocs[tempLength - 1];
						 pri[tempLength] = pri[tempLength - 1];
					 }
					 queuePrintDocs[pos] = userDoc;
					 pri[pos] = usersPriority;
					 length+=2;	// +1 - на добавленный элемент, +1 - на счетчик (для следующего добавления)
					 return true;
				 }
			 }
		}
		 
		 //если очередь заполнена
		else {
			return false;
		}
	 }

	 // вывод документа на печать
	string extractDoc() {
		string temp = queuePrintDocs[0];
		// сдвигаем очередь
		for (int i = 0; i < length; i++) {
			queuePrintDocs[i] = queuePrintDocs[i + 1];
			pri[i] = pri[i + 1];
		}
		length--;
		return temp;
		User::deleteDoc(0);
	}

};

