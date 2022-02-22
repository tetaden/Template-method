#include "Classes.h"
#include "Time.h"
#include <iostream>
using namespace std;


int main() {
	Vector<Time> a(4);
	Time t(100, 50);
	a.PushBack(t);

	/*Vector<Time> a(4);
	cout << "Is empty?: " << a.empty() << endl;
	cin >> a;
	a.PushBack(Time(31,21));
	cout << "Vector a" << a << endl;
	cout << "size of a: " << a.Size() << " capacity of a: " << a.Capacity() << endl;
	Vector<Time> b = a;
	cout << "Vector b" << b << endl;
	cin >> b >> b;
	cout << "Vector b" << b << endl;
	b.pop(3);
	cout << "Vector b" << b << endl;*/
	
	return 0;
}
//Vector<int> a(4);
	//cout << "Is empty?: " << a.empty() << endl;
	//cin >> a;
	//a.PushBack(2);
	//cout << "Vector a" << a << endl;
	//cout << "size of a: " << a.Size() << " capacity of a: " << a.Capacity() << endl;
	//Vector<int> b = a;
	//cout << "Vector b" << b << endl;
	//Vector<double>c{ 9.1,3.2,5.5 };
	//cout << "Vector c:";
	//c.Display();
	//cout << "1 entry: " << c[0]<< " last entry: " << c[2] << endl;
	//c.pop(2);
	//a.pop(0);
	//cout << "Vector a" << a << "Vector c" << c;
	//Vector<float> d{ 1.42, 1.32, 0.24, -5.1, -12, 1.1 };
	//cout << "Vector d"; d.Display();
	//cout << "Vector d, after eliminating 2 and 5 entry:";
	//d.pop(1);
	//d.pop(3); // 3- так как индекс сместился на 1(должно было быть 4)
	//d.Display();
	//Vector<float> e{ 1.2, 3.4, 5.6 };
	//cout << "Vector e: " << e;
	//d = e;
	//cout << "Vector d"; d.Display();