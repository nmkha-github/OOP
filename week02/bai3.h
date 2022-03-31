#pragma once
#include <string>
#include <iostream>
using namespace std;
template <class T>
struct node {
	T data;
	node <T>* next;
};
template <class T>
class List
{
private:
	node <T>* head;
	node <T>* tail;
	int size_;
	node <T>* createNode(T val) {
		node <T>* p = new node <T>;
		p->data = val;
		p->next = NULL;
		return p;
	}
public:
	List();
	List(T valHead);
	List(T valHead, T valTail);
	void insertNode(T val, int pos);
	void deleteNode(int pos);
	int getSize();
	T getValueAt(int pos);
	~List();
};

template <class T>
List <T>::List() {
	head = NULL;
	tail = NULL;
	size_ = 0;
}
template <class T>
List <T>::List(T valHead) {
	head = createNode(valHead);
	tail = head;
	size_ = 1;
}
template <class T>
List <T>::List(T valHead, T valTail) {
	head = createNode(valHead);
	tail = createNode(valTail);
	head->next = tail;
	size_ = 2;
}
template <class T>
void List <T>::insertNode(T val, int pos) {
	node <T>* add = createNode(val);
	if (pos > 0 && pos < size_ - 1) {
		node <T>* p = head;
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
		tail = head;
		size_++;
	}
	else if (pos == size_) {
		tail->next = add;
		tail = add;
		size_++;
	}
}
template <class T>
void List <T>::deleteNode(int pos) {
	if (pos > 0 && pos < size_) {
		node <T>* p = head;
		for (int i = 0; i < pos - 1; i++) {
			p = p->next;
		}
		node <T>* del = p->next;
		p->next = del->next;
		delete del;
		if (pos == size_ - 1) {
			tail = p;
		}
		size_--;
	}
	else if (pos == 0) {
		node <T>* p = head;
		head = head->next;
		delete p;
		size_--;
	}
}
template <class T>
int List <T>::getSize() {
	return size_;
}
template <class T>
T List <T>::getValueAt(int pos) {
	if (pos < 0)
		return NULL;
	else if (pos >= 0 && pos < size_) {
		node <T>* p = head;
		for (int i = 0; i < pos; i++)
			p = p->next;
		return p->data;
	}
}
template <class T>
List <T>::~List() {
	while (head) {
		node <T>* del = head;
		head = head->next;
		delete del;
	}
	delete head;
}
template <class T>
class Queue
{
private:
	List <T> list;
public:
	void push(T data);
	void pop();
	T top();
	int size();
};
template <class T>
void Queue <T>::push(T data)
{
	list.insertNode(data, list.getSize());
}
template <class T>
void Queue <T>::pop() {
	if (list.getSize() == 0) return;
	list.deleteNode(0);
}
template <class T>
T Queue <T>::top() {
	return list.getValueAt(0);
}
template <class T>
int Queue <T>::size() {
	return list.getSize();
}
