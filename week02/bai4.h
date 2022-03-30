#pragma once
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
    ~Vector();
    void push_back(T val);
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
Vector <T>::~Vector() {
    delete[] arr;
}

template <class T>
void Vector <T>::push_back(T val) {
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



struct DinhKe {
    int val, cost;
    DinhKe* next;
};

struct Canh {
    int DinhDau, DinhCuoi, TrongSo;
};

class Graph {

    DinhKe* ThemDinhVaoDanhSachKe(int value, int trongso, DinhKe* head) {
        DinhKe* newNode = new DinhKe;
        newNode->val = value;
        newNode->cost = trongso;

        newNode->next = head;
        return newNode;
    }
    int N;
public:
    DinhKe** head; // danh sach ke la mang con tro

    // constructor
    Graph(Canh CacCanh[], int n, int N) {
        head = new DinhKe * [N]();
        this->N = N;

        for (int i = 0; i < N; ++i)
            head[i] = nullptr;

        for (unsigned i = 0; i < n; i++) {
            int DinhDau = CacCanh[i].DinhDau;
            int DinhCuoi = CacCanh[i].DinhCuoi;
            int TrongSo = CacCanh[i].TrongSo;

            DinhKe* newNode = ThemDinhVaoDanhSachKe(DinhCuoi, TrongSo, head[DinhDau]);


            head[DinhDau] = newNode;
        }
    }
    // destructor
    ~Graph() {
        for (int i = 0; i < N; i++)
            delete[] head[i];
        delete[] head;
    }
    int* BFS();
};

int* Graph::BFS() {
    int* res = new int[10];
    return res;
}
void CanhKeCuaMotDinh(DinhKe* ptr, int i)
{
    while (ptr != nullptr) {
        cout << "(" << i << ", " << ptr->val
            << ", " << ptr->cost << ") ";
        ptr = ptr->next;
    }
    cout << endl;
}
