#pragma once
#include "Type.h"

TypesList::TypesList() {
	counter = 0;
	begin = NULL;
	end = NULL;
}

TypesList::~TypesList() {
	removeAll();
}

void TypesList::show() {
	Types *p = begin;

	if (begin == NULL) {
		cout << "TypesList is empty\n";
		return;
	}

	while (p != NULL) {
		cout << p->name << "\n";
		p = p->next;
	}
	cout << endl;
	cout << "number of elements : " << counter << endl;
}

Types* TypesList::find(string name) {
	Types *p = begin;

	if (name == "") {
		cout << "can not find empty name\n";
		return NULL;
	}

	if (begin == NULL) {
		cout << "TypesList is empty\n";
		return NULL;
	}


	while (p != NULL) {
		if (p->name == name) {
			cout << p->name << " found!\n";
			break;
		}
		p = p->next;
	}

	if (p == NULL)
		cout << name << " not found!\n";
	return p;
}

void TypesList::remove(Types* r) {
	if (r == NULL) {
		cout << "element to remove not found\n";
		return;
	}

	if (r->prev) {
		r->prev->next = r->next;
	}
	else {
		begin = r->next;
	}

	if (r->next) {
		r->next->prev = r->prev;
	}
	else {
		end = r->prev;
	}
	delete r;
	counter--;
}

void TypesList::removeAll() {
	Types *p;

	if (begin == NULL) {
		cout << "TypesList is empty\n";
		return;
	}

	while (begin != NULL) {
		p = begin->next;
		delete begin;
		begin = p;
	}
	cout << "TypesList is deleted\n";
}

void TypesList::addStart(string name) {
	if (name == "") {
		cout << "can not add empty data\n";
		return;
	}

	Types *p = new Types;
	if (p != NULL) {
		p->name = name;
		p->next = begin;
		p->prev = NULL;
		begin = p;
		counter++;

		if (p->next) {//next exists
			p->next->prev = p;
		}
		else { //empty list
			end = p;
		}
		cout <<" new data added to the start of TypesList\n";
	}
	else {
		cout << "memory error";
	}
}

void TypesList::addEnd(string name) {
	if (name == "") {
		cout << "can not add empty data\n";
		return;
	}

	Types* p = new Types;

	if (p != NULL) {
		p->name = name;
		p->prev = end;
		p->next = NULL;
		end = p;
		counter++;

		if (p->prev) {//previous exists
			p->prev->next = p;
		}
		else { //empty list
			begin = p;
		}
		cout <<" new data added to the end of TypesList\n";
	}
	else {
		cout << "memory error";
	}
}

void TypesList::addAfter(Types* r, string name) {
	if (name == "") {
		cout << "can not add empty data\n";
		return;
	}

	if (r == NULL) {
		cout << "element after not found\n";
		return;
	}

	if (r == end) {
		addEnd(name);
	}
	else {
		Types *p = new Types;
		if (p != NULL) {
			p->name = name;
			p->next = r->next;
			p->prev = r;
			counter++;
			r->next->prev = p;
			r->next = p;
			cout <<" new data added after " << r->name << " in the TypesList\n";
		}
		else {
			cout << "memory error";
		}
	}
}

void TypesList::addBefore(Types *r, string name) {
	if (name == "") {
		cout << "can not add empty data\n";
		return;
	}

	if (r == NULL) {
		cout << "element before not found\n";
		return;
	}

	if (r == begin) {
		addStart(name);
	}
	else {
		Types* p = new Types;
		if (p != NULL) {
			p->name = name;
			p->next = r;
			p->prev = r->prev;
			counter++;
			r->prev->next = p;
			r->prev = p;
			cout <<" added before " << r->name << " in the TypesList\n";
		}
		else {
			cout << "memory error";
		}
	}
}

void TypesList::delBegin() {
	if (counter > 0) {
		remove(begin);
		cout << "first element deleted from the TypesList\n";
	}
}

void TypesList::delEnd() {
	if (counter > 0) {
		remove(end);
		cout << "last element deleted from the TypesList\n";
	}
}