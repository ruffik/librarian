#pragma once
#include "Back.h"

BackList::BackList() {
	counter = 0;
	begin = NULL;
	end = NULL;
}

BackList::~BackList() {
	removeAll();
}

void BackList::show() {
	Back *p = begin;

	if (begin == NULL) {
		cout << "BackList is empty\n";
		return;
	}

	while (p != NULL) {
		cout << p->name << "\n";
		p = p->next;
	}
	cout << endl;
	cout << "number of elements : " << counter << endl;
}

Back* BackList::find(string name) {
	Back *p = begin;

	if (name == "") {
		cout << "can not find empty name\n";
		return NULL;
	}

	if (begin == NULL) {
		cout << "BackList is empty\n";
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

void BackList::remove(Back* r) {
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

void BackList::removeAll() {
	Back *p;

	if (begin == NULL) {
		cout << "BackList is empty\n";
		return;
	}

	while (begin != NULL) {
		p = begin->next;
		delete begin;
		begin = p;
	}
	cout << "BackList is deleted\n";
}

void BackList::addStart(string name) {
	if (name == "") {
		cout << "can not add empty data\n";
		return;
	}

	Back *p = new Back;
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
		cout <<" new data added to the start of BackList\n";
	}
	else {
		cout << "memory error";
	}
}

void BackList::addEnd(string name) {
	if (name == "") {
		cout << "can not add empty data\n";
		return;
	}

	Back* p = new Back;

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
		cout <<" new data added to the end of BackList\n";
	}
	else {
		cout << "memory error";
	}
}

void BackList::addAfter(Back* r, string name) {
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
		Back *p = new Back;
		if (p != NULL) {
			p->name = name;
			p->next = r->next;
			p->prev = r;
			counter++;
			r->next->prev = p;
			r->next = p;
			cout <<" new data added after " << r->name << " in the BackList\n";
		}
		else {
			cout << "memory error";
		}
	}
}

void BackList::addBefore(Back *r, string name) {
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
		Back* p = new Back;
		if (p != NULL) {
			p->name = name;
			p->next = r;
			p->prev = r->prev;
			counter++;
			r->prev->next = p;
			r->prev = p;
			cout <<" added before " << r->name << " in the BackList\n";
		}
		else {
			cout << "memory error";
		}
	}
}

void BackList::delBegin() {
	if (counter > 0) {
		remove(begin);
		cout << "first element deleted from the BackList\n";
	}
}

void BackList::delEnd() {
	if (counter > 0) {
		remove(end);
		cout << "last element deleted from the BackList\n";
	}
}