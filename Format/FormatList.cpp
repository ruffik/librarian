#include "Format.h"

FormatList::FormatList() {
	counter = 0;
	begin = NULL;
	end = NULL;
}

FormatList::~FormatList() {
	removeAll();
}

void FormatList::show() {
	Format *p = begin;

	if (begin == NULL) {
		cout << "FormatList is empty\n";
		return;
	}

	while (p != NULL) {
		cout << p->name << "\n";
		p = p->next;
	}
	cout << endl;
	cout << "number of elements : " << counter << endl;
}

Format* FormatList::find(string name) {
	Format *p = begin;

	if (name == "") {
		cout << "can not find empty name\n";
		return NULL;
	}

	if (begin == NULL) {
		cout << "FormatList is empty\n";
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

void FormatList::remove(Format* r) {
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

void FormatList::removeAll() {
	Format *p;

	if (begin == NULL) {
		cout << "FormatList is empty\n";
		return;
	}

	while (begin != NULL) {
		p = begin->next;
		delete begin;
		begin = p;
	}
	cout << "FormatList is deleted\n";
}

void FormatList::addStart(string name) {
	if (name == "") {
		cout << "can not add empty data\n";
		return;
	}

	Format *p = new Format;
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
		cout <<" new data added to the start of FormatList\n";
	}
	else {
		cout << "memory error";
	}
}

void FormatList::addEnd(string name) {
	if (name == "") {
		cout << "can not add empty data\n";
		return;
	}

	Format* p = new Format;

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
		cout <<" new data added to the end of FormatList\n";
	}
	else {
		cout << "memory error";
	}
}

void FormatList::addAfter(Format* r, string name) {
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
		Format *p = new Format;
		if (p != NULL) {
			p->name = name;
			p->next = r->next;
			p->prev = r;
			counter++;
			r->next->prev = p;
			r->next = p;
			cout <<" new data added after " << r->name << " in the FormatList\n";
		}
		else {
			cout << "memory error";
		}
	}
}

void FormatList::addBefore(Format *r, string name) {
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
		Format* p = new Format;
		if (p != NULL) {
			p->name = name;
			p->next = r;
			p->prev = r->prev;
			counter++;
			r->prev->next = p;
			r->prev = p;
			cout <<" added before " << r->name << " in the FormatList\n";
		}
		else {
			cout << "memory error";
		}
	}
}

void FormatList::delBegin() {
	if (counter > 0) {
		remove(begin);
		cout << "first element deleted from the FormatList\n";
	}
}

void FormatList::delEnd() {
	if (counter > 0) {
		remove(end);
		cout << "last element deleted from the FormatList\n";
	}
}