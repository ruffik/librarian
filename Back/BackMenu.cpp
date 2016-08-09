#pragma once
#include <iostream>
#include "Back.h"
using namespace std;

BackList back;
Back *b;

void bmenu() {
	char choice;
	do
	{
		cout << "Book backs menu\n\n";
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
			bshow();
			break;
		case '2':
			baddBegin();
			break;
		case '3':
			baddEnd();
			break;
		case '4':
			bdelBegin();
			break;
		case '5':
			bdelEnd();
			break;
		case '6':
			bremoveAll();
			break;
		case '0':
			break;
		default:
			breset();
			break;
		};
	} while (choice != '0');
}

void bshow() {
	system("cls");
	back.show();
	system("pause");
	system("cls");
}

void baddBegin() {
	system("cls");
	back.addStart("paperback");
	system("pause");
	system("cls");
}

void baddEnd() {
	system("cls");
	back.addEnd("hardback");
	system("pause");
	system("cls");
}

void bdelBegin() {
	system("cls");
	back.delBegin();
	system("pause");
	system("cls");
}

void bdelEnd() {
	system("cls");
	back.delEnd();
	system("pause");
	system("cls");
}

void bremoveAll() {
	system("cls");
	back.removeAll();
	system("pause");
	system("cls");
}

void breset() {
	system("cls");
	cout << "wrong choice try again\n" << endl;
	system("pause");
	system("cls");
}