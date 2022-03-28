#pragma once
#include <iostream>
using namespace std;
template <class T>
class Vector {
private:
	int _size;
	T* arr;
public:
	Vector();
	~Vector();
	void push_back(T val);
	int size();
	T& operator[](int index);
};
template <class T>
Vector <T>::Vector() {
	this->_size = 0;
	this->arr = new T[200010];
}
template <class T>
Vector <T>::~Vector() {
	delete[] arr;
}
template <class T>
void Vector <T>::push_back(T val) {
	arr[_size++] = val;
}
template <class T>
int Vector <T>::size() {
	return _size;
}
template <class T>
T& Vector <T>::operator[](int index) {
	return arr[index];
};

class Graph {
private:
	
public:
	int* BFS();
};
int* Graph::BFS() {
	int* res = new int[10];
	return res;
}