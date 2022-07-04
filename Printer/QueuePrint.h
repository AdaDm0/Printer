//#include "User.h"
#include <iostream>
#include <string.h>
#pragma once
using namespace std;

class QueuePrint
{
private:
	string* queuePrintDocs;	//������� ������
	int length;	//����� �������
	int maxLength;	//������������ ����� �������
	int* pri;	//���������
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

	//������������� ������� ��� ������� � ������� ��������� � ������� ������������
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

	// �������� ����� ������� �������
	int getQueueLength() {
		return length;
	}

	//���������� ��������� ������������ � ������� (������� � ������������ ����������)
	 bool addPrintQueue (string &userDoc, int &usersPriority) {
		 //���� ������� ������ (��� ����������), ������ ��������� �������� (���������� �� � ���)
		 if (isEmpty) {
			 queuePrintDocs[length] = userDoc;
			 this->pri[length] = usersPriority;
			 length++;
			 return true;
		}
		 
		 //���� ������� �� ��������� �� �����, �� ���� ����� ��� ��������� �������� ����������
		 else if (!isFull()) {
			 // (������ ��������� - 1, ������ - 5)
			 //���������� ���������� �� ������� � �������� �����������
			 int pos = 0;	// ������� �������
			 for (int i = 0; i < length; i++) {
				 if (pri[i] <= usersPriority) {
					 continue;
				 }
				 // ������� ����� ��� ������� ��������� � ������� (������� �������� � ������� ����� ��������� ���� ���������)
				 else {
					 pos = i;	//��������� ������� ��� ������� ���������
					 int tempLength = length + 1;	// ���������� ������� ����� �������
					 for (tempLength; tempLength>i; tempLength-- ) {
						 queuePrintDocs[tempLength] = queuePrintDocs[tempLength - 1];
						 pri[tempLength] = pri[tempLength - 1];
					 }
					 queuePrintDocs[pos] = userDoc;
					 pri[pos] = usersPriority;
					 length+=2;	// +1 - �� ����������� �������, +1 - �� ������� (��� ���������� ����������)
					 return true;
				 }
			 }
		}
		 
		 //���� ������� ���������
		else {
			return false;
		}
	 }

	 // ����� ��������� �� ������
	string extractDoc() {
		string temp = queuePrintDocs[0];
		// �������� �������
		for (int i = 0; i < length; i++) {
			queuePrintDocs[i] = queuePrintDocs[i + 1];
			pri[i] = pri[i + 1];
		}
		length--;
		return temp;
		User::deleteDoc(0);
	}

};

