#pragma once
#include <iostream>
#include "Format.h"
using namespace std;

FormatList format;
Format *f;

void fmenu() {
	char choice;
	do
	{
		cout << "Book formats menu\n\n";
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
			fshow();
			break;
		case '2':
			faddBegin();
			break;
		case '3':
			faddEnd();
			break;
		case '4':
			fdelBegin();
			break;
		case '5':
			fdelEnd();
			break;
		case '6':
			fremoveAll();
			break;
		case '0':
			break;
		default:
			freset();
			break;
		};
	} while (choice != '0');
}


void fshow() {
	system("cls");
	format.show();
	system("pause");
	system("cls");
}

void faddBegin() {
	system("cls");
	format.addStart("A5");
	system("pause");
	system("cls");

}

void faddEnd() {
	system("cls");
	format.addEnd("B5");
	system("pause");
	system("cls");
}

void fdelBegin() {
	system("cls");
	format.delBegin();
	system("pause");
	system("cls");
}

void fdelEnd() {
	system("cls");
	format.delEnd();
	system("pause");
	system("cls");
}

void fremoveAll() {
	system("cls");
	format.removeAll();
	system("pause");
	system("cls");
}

void freset() {
	system("cls");
	cout << "wrong choice try again\n" << endl;
	system("pause");
	system("cls");
}