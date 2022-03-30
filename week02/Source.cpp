#include "bai3.h"
#include "bai4.h"
using namespace std;
int main() {
	Vector <int> a;
	a.push_back(10);
	a.push_back(11);
	for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
	
	cout << "Hello world";
	/* Canh CacCanh[] = {
        // (x, y, w) -> canh tu dinh x den dinh y voi trong so la w
        {0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3},{1,2,3}
    };

    int N = 6;  // So dinh cua do thi
    int n = sizeof(CacCanh) / sizeof(CacCanh[0]);  // tinh so canh
  
    Graph graph(CacCanh, n, N);

    cout << "Danh sach ke: " << endl << "(Dinh dau, Dinh cuoi, trong so):" << endl;
    for (int i = 0; i < N; i++)
    {
      
        CanhKeCuaMotDinh(graph.head[i], i);
    }
    return 0; */
}
