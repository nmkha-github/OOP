#pragma once
#include <string>
using namespace std;

struct node {
	string data;
	node* next;
};

class List
{
private:
	node* head;
	node* tail;
	int size_;
	node* createNode(string val) {
		node* p = new node;
		p->data = val;
		p->next = NULL;
		return p;
	}
public:
	List();
	List(string valHead);
	List(string valHead, string valTail);
	void insertNode(string val, int pos);
	void deleteNode(int pos);
	int getSize();
	string getValueAt(int pos);
	~List();
};

List::List() {
	head = new node;
	tail = new node;
	size_ = 0;
}

List::List(string valHead) {
	head = createNode(valHead);
	tail = head;
	size_ = 1;
}

List::List(string valHead, string valTail) {
	head = createNode(valHead);
	tail = createNode(valTail);
	head->next = tail;
	size_ = 2;
}

void List::insertNode(string val, int pos) {
	node* add = createNode(val);
	if (pos > 0 && pos < size_-1) {
		node* p = head;
		for (int i = 0; i < pos; i++) {
			p = p->next;
		}
		add->next = p->next;
		p->next = add;
		size_++;
	}
	else if (pos == 0) {
		add->next = head;
		head = add;
		size_++;
	}
	else if(pos == size_ - 1) {
		tail->next = add;
		tail == add;
		size_++;
	}
}

void List::deleteNode(int pos) {
	if (pos > 0 && pos < size_) {
		node* p = head;
		for (int i = 0; i < pos-1; i++) {
			p = p->next;
		}
		node* del = p->next;
		p->next = del->next;
		delete del;
		if (pos == size_ - 1) {
			tail = p;
		}
		size_--;
	}
	else if (pos == 0) {
		node* p = head;
		head = head->next;
		delete p;
		size_--;
	}
}

int List::getSize() {
	return size_;
}

string List::getValueAt(int pos) {
	if (pos < 0)
		return "NULL";
	else if (pos >= 0 && pos < size_) {
		node* p = head;
		for (int i = 0; i < pos; i++)
			p = p->next;
		return p->data;
	}
}

List::~List() {
	while (!head) {
		node* del = head;
		head = head->next;
		delete del;
	}
	delete head;
	delete tail;
}

class Queue
{
private:
	List list;
public:
	void push(string data);
	void pop();
	string top();
	int size();
};

void Queue::push(string data)
{
	list.insertNode(data, 0);
}

void Queue::pop() {
	list.deleteNode(0);
}

string Queue::top() {
	return list.getValueAt(0);
}

int Queue::size() {
	return list.getSize();
}

int main() {
	Queue q;
	q.push("hello");
	cout << q.top();
	return 1;
}
