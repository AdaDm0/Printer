#include <iostream>
#pragma once
using namespace std;

class User
{
private:
	int priority;
	string* docs;
	int maxNum=5;
	int docNum=0;	//���������� ����������: 1. ����� ��������� � �������! ������ ������� ������������, 2. ������� ���������� ���������� � �������
public:
//User() {};
	User(int priority) : priority{ priority }, docs{ new string [maxNum]}{}

	//�������� �������� � ������� ������
	void add(string document) {
		//if (!isFull()) {
		docs[docNum++] = document;	//���������� ������ � �������, ����� ���� ����������� �������� docNum, ����� ����������� ���������� ��������
		cout << "Doc is added to print queue." << endl;
	}
		/*else {
			cout << "Queue is full. Try again later." << endl;
		}
	}*/

	//������� �������� �� ������� ������
	void deleteDoc (int docNumToDelete) {
		if (docNumToDelete <= (docNum - 1)&&(docNumToDelete>0)) {
			cout << "Deleting doc N " << docNumToDelete << endl;
			for (int i = 0; i < docNum; i++) {
				if (i < docNumToDelete)	// ���� i ������ ������� �������� ��� �������� - ����������
					continue;
				else if (i >= docNumToDelete) {	// ���� i ����� ��� ������ ��������� �������, �� �������������� � ������� ������ �������� ��������� ������
					docs[i] = docs[i + 1];
				}
			}
			docNum--;	// ��������� ������� ��������� � ������� �������
		}
		else {
			cout << "Wrong number!";
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

	//������� ������ ������� ������������
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

