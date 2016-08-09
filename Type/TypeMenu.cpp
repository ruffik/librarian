#pragma once
#include <iostream>
#include "Type.h"
using namespace std;

TypesList Type;
Types *t;

void tmenu() {
	char choice;
	do
	{
		cout << "Book Types menu\n\n";
		cout << "1. show\n";
		cout << "2. add to begin\n";
		cout << "3. add to end\n";
		cout << "4. remove begin\n";
		cout << "5. remove end\n";
		cout << "6. remove all\n";
		cout << "0. back\n\n";

		cin >> choice;
		switch (choice) {
		case '1':
			tshow();
			break;
		case '2':
			taddBegin();
			break;
		case '3':
			taddEnd();
			break;
		case '4':
			tdelBegin();
			break;
		case '5':
			tdelEnd();
			break;
		case '6':
			tremoveAll();
			break;
		case '0':
			break;
		default:
			treset();
			break;
		};
	} while (choice != '0');
}

void tshow() {
	system("cls");
	Type.show();
	system("pause");
	system("cls");
}

void taddBegin() {
	system("cls");
	Type.addStart("biography");
	system("pause");
	system("cls");
}

void taddEnd() {
	system("cls");
	Type.addEnd("novel");
	system("pause");
	system("cls");
}

void tdelBegin() {
	system("cls");
	Type.delBegin();
	system("pause");
	system("cls");
}

void tdelEnd() {
	system("cls");
	Type.delEnd();
	system("pause");
	system("cls");
}

void tremoveAll() {
	system("cls");
	Type.removeAll();
	system("pause");
	system("cls");
}

void treset() {
	system("cls");
	cout << "wrong choice try again\n" << endl;
	system("pause");
	system("cls");
}