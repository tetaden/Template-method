#pragma once
#include <iostream>
using namespace std;
void exam(int a, int b) {
	if (a > 60 || b > 60) {
		throw  "Error 101, minutes and seconds shouldn`t be more than 60";
	}
	else if (a < 0 || b < 0) {
		throw "Error 102, minutes and seconds must be positive numbers";
	}
}
class Time {
private:
	int min, sec;
public:
	Time(void); 
	explicit Time(int, int = 0);
	~Time() {};
	Time(const Time&);
	friend ostream& operator <<(ostream&, const Time&);
	friend istream& operator>>(istream& in, Time& t);
	void Create(void);
	void Display(void);
	Time& operator =(const Time&);
	
};
Time::Time(void) :min(0), sec(0) {};
Time::Time(int a, int b) :min(a), sec(b) {
	if (min > 60 || sec > 60) {
		cout << endl<< "Error 101, minutes and seconds shouldn`t be more than 60. Your values: " << min << " and " << sec << " respectively" << endl;
		abort();
	}
	else if(min < 0 || sec < 0) {
		cout <<endl<< "Error 102, minutes and seconds must be positive numbers. Your values: " << min << " and " << sec << " respectively" << endl;
		abort();
	}
}
Time::Time(const Time& other) :min(other.min), sec(other.sec) {};
ostream& operator <<(ostream& os, const Time& a) {
	os << a.min << ":" << a.sec;
	return os;
}
void Time::Create(void) {
	cout << "Set time interval: ";
	while (cin >> min >> sec) {
		try {
			exam(min, sec);
		}
		catch(const char* s){
			cout << s << endl << "Set new numbers:";
			continue;
		}
		break;
	}
}
void Time::Display(void) {
	cout << min << ":" << sec << endl;
}
Time& Time::operator=(const Time& other){
	min = other.min;
	sec = other.sec;
	return *this;
}
istream& operator>>(istream& in, Time& t)
{
	cout << "min:"; in >> t.min;
	cout << "sec:"; in >> t.sec;
	if (t.min > 60 || t.sec > 60) {
		cout << endl << "Error 101, minutes and seconds shouldn`t be more than 60. Your values: " << t.min << " and " << t.sec << " respectively" << endl;
		abort();
	}
	else if (t.min < 0 || t.sec < 0) {
		cout << endl << "Error 102, minutes and seconds must be positive numbers. Your values: " << t.min << " and " << t.sec << " respectively" << endl;
		abort();
	}
	return in;
}

