#pragma once
#include <iostream>
using namespace std;

template <class T>
class Vector {
private:
	int size, capacity;
	T* data;
public:
	Vector();// конструктор по умолчанию
	explicit Vector(int); // конструктор, создающий вектор из n  пустых элементов 
	Vector(const Vector&); // конструктор копирования 
	explicit Vector(const initializer_list<T>& list); //инициализация веткора 
	~Vector(); // деструктор 
	void PushBack(const T&); // добавление элемента в конец 
	T* begin() const; // получение указателя на начало массива 
	T* end() const; // получение указателя на конец массива 
	friend ostream& operator << <>(ostream&, const Vector&); // перегрузка оператора <<
	friend istream& operator >> <>(istream&, Vector&); // перегрузка оператора >> 
	void Display() const; // отображение значений вектора 
	Vector operator = (const Vector& other); // оператор присваивания 
	T& operator[](int); // получение значения элемента вектора 
	T pop(int); // удаление вектора 
	int Size()const; // отображение значения size вектора 
	int Capacity()const;// отображение значения capacity вектора 
	bool empty(); //Проверка на пустоту
	T& get_value(int);
};
template <class T>
Vector<T>::Vector() :size(0), capacity(0) {};

template <class T>
Vector<T>::Vector(int n) :size(0), capacity(n), data(new T[n]) {};

template <class T>
Vector<T>::Vector(const Vector<T>& other) :size(other.size), capacity(other.capacity), data(new T[capacity]) {
	copy(other.data, other.data + size, data);
}

template <class T>
Vector<T>::Vector(const initializer_list<T>& list) : size(0), capacity(list.size()), data(new T[capacity]) {
	for (T i : list) PushBack(i);
}
template <class T>
Vector<T>::~Vector() {
	delete[]data;
}

template <class T>
void Vector<T>::PushBack(const T& value) {
	if (size == capacity) { // если все значения заполнены...
		T* old = data;
		data = new T[++capacity];
		copy(old, old + size, data);  //с помощью функции copy копируем в массив data все значения с начала старого массива до его конца
		// объекты old и old +size представляют собой указатели на начало  и конец массива
		delete[] old;
	}
	data[size++] = value;
}

template <class T>
T* Vector<T>::begin() const {
	return data;
}

template <class T>
T* Vector<T>::end() const {
	return data + size;
}

template <class T>
void Vector<T>::Display()const  // Вывод вектора
{
	cout << '{';
	T* ptr;
	for (ptr = begin(); ptr != end(); ptr++) {
		cout << *ptr << ' ';
	}
	cout << '}';
	cout << '\n';
}


template <class T>
Vector<T> Vector<T>::operator=(const Vector<T>& other)// Оператор присваивания 
{
	delete[] data;
	data = new T[other.capacity];
	capacity = other.capacity;
	size = other.size;
	copy(other.data, other.data + other.size, data);
	return *this;
}

template <class T>
T& Vector<T>:: operator[](int index) {
	if (index > capacity) {
		cout << "Erorr 104, Index " << index << " out of the range " << capacity << endl;
		abort();
	}
	return data[index];
}
template <class T>
ostream& operator <<(ostream& os, const Vector<T>& a) { // Еще один вывод вектора  c перегруженным оператором 
	T* ptr;
	os << '{';
	for (ptr = a.begin(); ptr != a.end(); ptr++) {
		os << *ptr << ' ';
	}
	os << '}';
	return os;

}
template<class T>
istream& operator >>(istream& is, Vector<T>& s) {
	T x;
	is >> x;
	s.PushBack(x);
	return is;
}

template<class T>
T Vector<T>::pop(int a) {
	T result = data[a];
	T* new_data = new T[capacity - 1];
	if (a + 1 < capacity) {
		copy(data, data + a + 1, new_data);
		copy(data + a + 1, data + capacity, new_data + a);
	}
	else if (a + 1 == capacity) {
		copy(data, data + capacity - 1, new_data);
	}
	else if (a + 1 > capacity) {
		cout << "Erorr 103, Index " << a << " out of the range " << capacity << endl;
		abort();
	}
	delete[]data;
	capacity--;
	size--;
	data = new_data;
	return result;
}

template<class T>
int Vector<T>::Size(void)const {
	return size;
}

template<class T>
int Vector<T>::Capacity(void)const {
	return capacity;
}
template <class T>
bool Vector<T>::empty() {
	return (size == 0);
}

template<class T>
T& Vector<T>::get_value(int index) {
	if (index > capacity) {
		cout << "Erorr 104, Index " << index << " out of the range " << capacity << endl;
		abort();
	}
	return data[index];
}