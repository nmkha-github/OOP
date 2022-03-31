#pragma once
#include "bai3.h"
#include <iostream>
using namespace std;

template <class T>
class Vector {
private:
    int _size;
    int _capacity;
    T* arr;
public:
    Vector();
    Vector(int n, T val);
    //~Vector();
    void push_back(const T& val);
    int size();
    T& operator[](int index);
};

template <class T>
Vector <T>::Vector() {
    this->_size = 0;
    this->_capacity = 1;
    this->arr = new T[_capacity];
}
template <class T>
Vector <T>::Vector(int n, T val) {
    this->_size = 0;
    this->_capacity = n;
    this->arr = new T[_capacity];
    for (int i = 0; i < _capacity; i++) this->arr[i] = val;
}
//template <class T>
//Vector <T>::~Vector() {
//    if (arr != NULL) delete[] arr;
//}

template <class T>
void Vector <T>::push_back(const T& val) {
    if (_capacity < _size + 1) {
        T *del = this->arr;
        _capacity *= 2;
        this->arr = new T[_capacity];
        for (int i = 0; i < _size; i++) this->arr[i] = del[i];
    }
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
    Vector <int>* _danhSachKe;
    int _N;
public:
    Graph();
    ~Graph();
    void input();
    Vector <int> bfs(int u);
};
Graph::Graph() {
    _danhSachKe = NULL;
    _N = 0;
}
Graph::~Graph() {
    if (_danhSachKe != NULL) delete[] _danhSachKe;
}
void Graph::input() {
    cout << "Nhap so dinh: "; cin >> this->_N;
    _danhSachKe = new Vector <int>[_N + 1];
    int n;
    cout << "Nhap so canh: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap canh thu " << i + 1 << ":\n";
        int u, v;
        cout << "Nhap dinh 1: "; cin >> u;
        cout << "Nhap dinh 2: "; cin >> v;
        this->_danhSachKe[u].push_back(v);
        this->_danhSachKe[v].push_back(u);
    }
}
Vector <int> Graph::bfs(int start) {
    Queue <int> q;
    Vector <bool> Free(_N + 1, 1);
    Vector <int> res;
    if (start > _N) {
        return res;
    }
    q.push(start);
    while (q.size()) {
        int u = q.top(); q.pop();
        Free[u] = 0;
        res.push_back(u);
        for (int i = 0; i < _danhSachKe[u].size(); i++) {
            int v = _danhSachKe[u][i];
            if (Free[v]) {
                q.push(v);
                Free[v] = 0;
            }
        }
    }
    return res;
}
