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
	int docNum;	//���������� ����������: 1. ����� ��������� � ������� ������ ��������, 2. ������� ���������� ���������� � �������
public:
	User() {};
	User(int priority) {
		if (priority > 0 && priority <= 5) {
			this->priority = priority;		// ��������� ������ ���� �� 1 �� 5, ��� 1 - ������ ���������, � 5 - ������ ���������
			maxNum = 5;
			docNum = 0;
			docs = new string[maxNum];
		}
		else
		{
			cout << "Wrong input. Priority must be 1-5." << endl;
		}
		
	}

	//������������� ������� ��� ����������� ��������� ������������ � ������� ��������
	//friend bool QueuePrint::addPrintQueue(string &userDoc, int &usersPriority);

	bool isFull() {
		return docNum == maxNum;
	}

	//�������� �������� � ������� ������ ������������ � ��������
	void addUserQueue(string document) {
		if (!isFull()) {
			docs[docNum] = document;	//���������� ������ � ������� ������ ������������
			// ��������� ���������� ��������� � ������� ��������
			bool res = QueuePrint::addPrintQueue(&docs[docNum], &priority);
			// ���������� ������������ � ���������� ��������� ������� ���������� � ������� ������ ��������
			if (res) {
				cout << "Doc is added to print queue." << endl;
				docNum++;	// ����������� �������� docNum, ����� ����������� ���������� ��������
			}
			else {
				cout << "Print queue if full. You can not print document now." << endl;
			}
		}
	}

	//������� �������� �� ������� ������
	void deleteDoc (int docNumToDelete) {
		if (docNumToDelete-1 <= (docNum - 1)&&(docNumToDelete>0)) {
			cout << "Deleting doc N " << docNumToDelete << "...  ";
			for (int i = 0; i < docNum; i++) {
				if (i < docNumToDelete-1)	// ���� i ������ ������� �������� ��� �������� - ����������
					continue;
				else if (i >= docNumToDelete-1) {	// ���� i ����� ��� ������ ��������� �������, �� �������������� � ������� ������ �������� ��������� ������
					docs[i] = docs[i + 1];
				}
			}
			cout << "Success." << endl;
			docNum--;	// ��������� ������� ��������� � ������� �������
		}
		else {
			cout << "Wrong number!"<<endl;
			}
		}

	//������� ������� ������
	void clearQueue() {	
		docNum = 0;
	}

	// ���������� ���������� � ������� (������� ��� ������� � �������)
	int getQueueLength() {
		return docNum;
	}
	
	void printQueueLength() {
		cout << "There is " << docNum << " document in the queue." << endl;
	}

	// ������� ��� ������ �� �������
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

	//���������� ������� ��������� �� ������� ������������
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

