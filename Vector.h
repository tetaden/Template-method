#pragma once
#include <iostream>
using namespace std;

template <class T>
class Vector {
private:
	int size, capacity;
	T* data;
public:
	Vector();// ����������� �� ���������
	explicit Vector(int); // �����������, ��������� ������ �� n  ������ ��������� 
	Vector(const Vector&); // ����������� ����������� 
	explicit Vector(const initializer_list<T>& list); //������������� ������� 
	~Vector(); // ���������� 
	void PushBack(const T&); // ���������� �������� � ����� 
	T* begin() const; // ��������� ��������� �� ������ ������� 
	T* end() const; // ��������� ��������� �� ����� ������� 
	friend ostream& operator << <>(ostream&, const Vector&); // ���������� ��������� <<
	friend istream& operator >> <>(istream&, Vector&); // ���������� ��������� >> 
	void Display() const; // ����������� �������� ������� 
	Vector operator = (const Vector& other); // �������� ������������ 
	T& operator[](int); // ��������� �������� �������� ������� 
	T pop(int); // �������� ������� 
	int Size()const; // ����������� �������� size ������� 
	int Capacity()const;// ����������� �������� capacity ������� 
	bool empty(); //�������� �� �������
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
	if (size == capacity) { // ���� ��� �������� ���������...
		T* old = data;
		data = new T[++capacity];
		copy(old, old + size, data);  //� ������� ������� copy �������� � ������ data ��� �������� � ������ ������� ������� �� ��� �����
		// ������� old � old +size ������������ ����� ��������� �� ������  � ����� �������
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
void Vector<T>::Display()const  // ����� �������
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
Vector<T> Vector<T>::operator=(const Vector<T>& other)// �������� ������������ 
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
ostream& operator <<(ostream& os, const Vector<T>& a) { // ��� ���� ����� �������  c ������������� ���������� 
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