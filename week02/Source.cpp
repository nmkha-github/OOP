#include "bai3.h"
#include "bai4.h"
int main() {
	//Test vector
	Vector <int> a;
	a.push_back(10);
	a.push_back(11);
	for (int i = 0; i < a.size(); i++) cout << a[i] << ' '; cout << endl;
	//Test List
	List <int> b;
	cout << b.getSize() << endl;
	b.insertNode(3, b.getSize());
	cout << b.getSize() << endl;
	b.insertNode(4, b.getSize());
	cout << b.getSize() << endl;
	cout << b.getValueAt(0) << ' ' << b.getValueAt(1) << endl;
	//Test Queue
	Queue <int> q;
	q.push(1);
	q.push(2);
	cout << q.top() << ' ' << q.size() << endl;	q.pop();
	cout << q.top() << ' ' << q.size() << endl; q.pop();
	q.pop();
	//Test Graph
	Graph G;
	G.input();
	G.bfs(0);
	cout << "\nHello world";
}
