#include "bai3.h"
#include "bai4.h"
int main() {
	//Test vector
	/*Vector <int> a;
	a.push_back(10);
	a.push_back(11);
	for (int i = 0; i < a.size(); i++) cout << a[i] << ' '; cout << endl;*/
	//Test List
	/*List <int> b;
	cout << b.getSize() << endl;
	b.insertNode(3, b.getSize());
	cout << b.getSize() << endl;
	b.insertNode(4, b.getSize());
	cout << b.getSize() << endl;
	cout << b.getValueAt(0) << ' ' << b.getValueAt(1) << endl;*/
	//Test Queue
	cout << "---------------Bai 3--------------------------\n";
	Queue <int> q;
	cout << "Them 1 2 3 vao hang doi.\n";
	q.push(1);
	q.push(2);
	q.push(3);
	cout << "Kich thuoc hang doi sau khi them: " << q.size() << endl;
	cout << "Gia tri phan tu top: " << q.top() << endl;
	cout << "Lay 2 phan tu ra khoi hang doi.\n";
	q.pop();
	q.pop();
	cout << "Gia tri phan tu top: " << q.top() << endl;
	cout << "Kich thuoc hang doi sau khi lay ra: " << q.size() << endl;
	cout << "Lay 1 phan tu ra khoi hang doi.\n";
	q.pop();
	cout << "Kich thuoc hang doi sau khi lay ra: " << q.size() << endl;
	//Test Graph
	cout << "---------------Do thi---------------------------\n";
	Graph G;
	G.input();
	int start;
	cout << "Chon dinh xuat phat: "; cin >> start;
	Vector <int> res = G.bfs(start);
	cout << "Thu tu duyet bfs tu " << start << ":\n";
	for (int i = 0; i < res.size(); i++) cout << res[i] << ' '; cout << endl;
}
