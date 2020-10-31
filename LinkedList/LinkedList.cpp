// Hello.cpp : This file contains the 'main' function. Program execution begins and ends there.
// hiros: freedisable

#include <iostream>
struct node {
	node(int value) : data(value), next(NULL) {};
	int data;
	node* next;
};
class List {
private:
	node* list;
	void push(node*& temp, int value);
	void del(node*& temp, int value);
	void sort(node*& temp);
	void top(node* temp);
	void free(node*& temp);
	void show_data(node* temp);
	void delNodeNext(node*& temp, int value);

public:
	List();
	~List();
	void addHead(int value) { push(list, value); } // add into head of list
	void delPos(int value) { del(list, value); } // delete any node 
	void sort() { sort(list); } // sort ASC
	void top() { top(list); } //value head of list
	void free() { free(list); }
	void show_data() { show_data(list); }
	void delNodeNext(int value){ delNodeNext(list, value); }
};
void List::show_data(node* temp) {
	if (temp != NULL) {
		std::cout << temp->data << " ";
		show_data(temp->next);
	}
}

void List::push(node*& temp, int value) {

	if (temp == NULL) {
		temp = new node(value);
		list = temp;
		return;
	}
	else if (temp->next == NULL) {
		node* p = new node(value);
		temp->next = p;
	}
	else
		push(temp->next, value);

}

List::List() {
	list = NULL;
}
void List::free(node*& temp) {
	if (temp == NULL)
		return;
	node* p = temp;
	free(temp->next);
	delete(p);
}
List::~List() {
	free();
}

void List::top(node* temp) {
	std::cout << temp->data;
}

void List::del(node*& temp, int value) {
	if (temp == NULL)
		return;
	if (temp->data == value) {
		node* p = temp;
		temp = temp->next;
		delete(p);
		return;
	}
	del(temp->next, value);
}
void List::sort(node*& temp) {
	if (temp == NULL)
		return;
	for (node* p = temp->next; p != NULL; p = p->next) {
		for (node* q = temp; q->next != NULL; q = q->next) {
			if (q->data > p->data) {
				int t = q->data;
				q->data = p->data;
				p->data = t;
			}
		}

	}
}

void List::delNodeNext(node*& temp, int value){
	if (temp == NULL)
		return;
	if (temp->data == value) {
		temp->next = temp->next->next;
		return;
	}
	delNodeNext(temp->next, value);
}
int main()
{
	List list;
	list.addHead(4);
	list.addHead(2);
	list.addHead(1);
	list.addHead(3);

	list.addHead(11);
	list.addHead(9);
	list.addHead(18);
	list.addHead(10);
	list.addHead(16);
	list.addHead(12);
	list.sort();
	list.delNodeNext(3);
	list.show_data();
	return 0;
}


