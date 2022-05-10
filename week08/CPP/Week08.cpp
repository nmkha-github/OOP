#include <iostream>
#include <vector>
using namespace std;

// Cau truc Diem
struct Point {
	double X, Y;
};

// Lop doi tuong hinh ve tong quat 'Shape'
class Shape {
public:
	// Contructors, Example: Shape(); ~Shape();
	Shape() {};
	~Shape() {};
	Shape(const Shape& s) {};
	/* Se cai dat lai trong tung lop dan xuat */
	virtual Shape* Clone() = 0;
	virtual bool IsSelected(Point p) = 0;
	// other methods, Example: input(); print();
	virtual void input() = 0;
	virtual void print() = 0;
};
// Lớp Circle
class Circle : public Shape {
protected:
	Point C;	//tọa độ tâm
	double R;	//độ dài bán kính
public:
	// Contructors
	Circle() {
		this->C.X = 0;
		this->C.Y = 0;
		this->R = 0;
	}
	// Detructors
	~Circle() {
		this->C.X = 0;
		this->C.Y = 0;
		this->R = 0;
	}
	// Copy Constructor
	Circle(const Circle& p) {
		this->C = p.C;
		this->R = p.R;
	}
	// Overriding base class's IsSelected method
	bool IsSelected(Point p) {
		return ((p.X - this->C.X) * (p.X - this->C.X) + (p.Y - this->C.Y) * (p.Y - this->C.Y)
			<= this->R * this->R);
	};
	// Overriding base class's Clone method
	Shape* Clone() {
		Circle* p = new Circle;
		if (p == NULL) return NULL;
		p->C = C;
		p->R = R;
		return p;
	}
	// Other methods,
	void input() {
		std::cout << "Nhap toa do tam hinh tron: "; std::cin >> this->C.X >> this->C.Y;
		std::cout << "Nhap ban kinh hinh tron: "; std::cin >> this->R;
	}
	void print() {
		std::cout << "Hinh tron tam (" << this->C.X << ',' << this->C.Y << "), ban kinh R = " << this->R;
	}
};
// Lớp hình chu nhat
class Rectangle : public Shape {
protected:
	Point X;		//tọa độ góc trái trên
	double W, H;	//chiều rộng và chiều cao
public:
	//Constructors
	Rectangle() {
		W = H = X.X = X.Y = 0;
	}
	// Destructors
	~Rectangle() {
		W = H = X.X = X.Y = 0;
	}
	// Copy Constructors
	Rectangle(const Rectangle& p) {
		this->X = p.X;
		this->W = p.W;
		this->H = p.H;
	}
	// Overriding base class's IsSelected method
	bool IsSelected(Point p) {
		return ((p.X >= X.X) && (p.X <= X.X + W)
			&& (p.Y >= X.Y) && (p.Y <= X.Y + H));
	}
	// Overriding base class's Clone method
	Shape* Clone() {
		Rectangle* p = new Rectangle;
		if (p == NULL) return NULL;
		p->X = X;
		p->W = W;
		p->H = H;
		return p;
	};
	// other methods
	void input() {
		std::cout << "Nhap toa do goc trai tren: "; std::cin >> this->X.X >> this->X.Y;
		std::cout << "Nhap chieu rong: "; std::cin >> this->W;
		std::cout << "Nhap chieu cao: "; std::cin >> this->H;
	}
	void print() {
		std::cout << "Hinh chu nhat co goc trai tren (" << this->X.X
			<< ',' << this->X.Y << "), chieu rong W = " << this->W
			<< ", chieu cao H = " << this->H;
	}
};
// Lớp ComplexShape
class ComplexShape : public Shape {
protected:
	// Các hình vẽ thành phần: Circle, rectangle, ...
	int sz;				//Number of Shapes
	Shape** Children;	//Array of <Shape*>
public:
	// Constructors
	ComplexShape() {
		this->sz = 0;
		this-> Children = new Shape * [sz];
	}
	//Destructors
	~ComplexShape() {
		this->sz = 0;
		this->Children = NULL;
	}
	// Copy Constructors
	ComplexShape(ComplexShape &a) {
		this->sz = a.sz;
		this->Children = a.Children;
	}

	// Overriding base class's IsSelected method
	bool IsSelected(Point p)
	{
		for (int i = 0; i < sz; i++)
		{
			if (Children[i]->IsSelected(p))
				return true;
		}
		return false;
	}
	// Overriding base class's Clone method
	Shape* Clone()  {
		ComplexShape* p = new ComplexShape;
		if (p == NULL) return NULL;
		p->sz = sz;
		p->Children = Children;
		return p;
		
	}
	//other methods
	void addShape(Shape* x) {
		ComplexShape a = new ComplexShape[sz + 1];
		for (int i = 0; i < sz; i++) {
			a.Children[i] = this->Children[i];
		}
		a.Children[sz] = x;
		this->sz++;
		delete[] this->Children;
		this->Children = a.Children;
	}

	void input()
	{
		int choice;
		cout << "1. Nhap hinh tron\n";
		cout << "2. Nhap hinh chu nhat\n";
		cout << "0. Thoat\n"
		Shape* x; // khai báo hình
		do {
			cin >> choice;
			if (choice == 0) {
				break;
			}
			else if (choice == 1)
			{
				x = new Circle;
				x->input();
			}
			else if (choice == 2)
			{
				x = new Rectangle;
				x->input();
			}
			else
				continue;
			// thêm hình vừa nhập vào mảng <Shape*>
			addShape(x);
		} while (true);
		
	}

	void print()
	{
		cout << "So hinh: " << sz << endl;
		for (int i = 0; i < sz; i++)
		{
			cout << "Hinh thu " << i + 1 << " :" << Children[i]->print() << endl;
		}
	}


};

int main()
{
	
}
