#pragma once
#include <iostream>
#include "Menu.h"
#include "../Back/Back.h"
#include "../Format/Format.h"
#include "../Type/Type.h"
using namespace std;

void menu() {
	char choice;

	do
	{
		cout << "Book library - descriptions\n\n";
		cout << "1. backs\n";
		cout << "2. formats\n";
		cout << "3. types\n";
		cout << "0. exit\n\n";

		cin >> choice;
		switch (choice) {
		case '1':
			system("cls");
			bmenu();
			system("cls");
			break;
		case '2':
			system("cls");
			fmenu();
			system("cls");
			break;
		case '3':
			system("cls");
			tmenu();
			system("cls");
			break;
		case '0':
			break;
		default:
			system("cls");
			cout << "wrong choice try again\n" << endl;
			system("pause");
			system("cls");
		};
	} while (choice != '0');
	cout << endl;
}

