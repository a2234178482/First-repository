#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <assert.h>
class Date {
public:
	friend ostream& operator<<(ostream& out, Date& d1);
	friend istream& operator>>(istream& in, Date& d1);
	Date(int year = 2025, int month = 4, int day = 22) {
		_year = year;
		_month = month;
		_day = day;
	}
	bool CheckDate() const
	{
		if (_month < 1 || _month > 12
			|| _day < 1 || _day > GetMonthDay(_year, _month))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	int GetMonthDay(int year, int month)const  {
		static int monthArray[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0) && year % 100 != 0) || (year % 400 == 0))
		{
			return 29;
		}
		return monthArray[month];
	}
	void Print() {
		cout << _year << "/" << _month << "/" << _day << endl;
	}
	Date& operator+=(int day) {
		_day += day;
		while (_day > GetMonthDay(_year, _month)) {
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13) {
				_year++;
				_month = 1;
			}
		}
		return *this;
	}
	Date& operator+(int day) {
		Date tmp = *this;
		tmp += day;
		return tmp;
	}
	Date& operator-(int day) {
		Date tmp = *this;
		tmp -= day;
		return tmp;
	}
	Date& operator-=(int day) {
		if (day < 0) {
			return *this += (-day);
		}
		_day -= day;
		while (_day < 0) {
			--_month;
			if (_month == 0) {
				_month = 12;
				--_year;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}
	bool operator==(const Date& d1) const {
		return _year == d1._year &&
			_month == d1._month &&
			_day == d1._day;
	}
	bool operator<(const Date& d1)const {
		if (_year < d1._year) {
			return true;
		}
		else if (_year == d1._year) {
			if (_month < d1._month) {
				return true;
			}
			else if (_month == d1._month) {
				return _day < d1._day;
			}
		}
		return false;
	}
	bool operator<=(const Date& d1) const {
		return *this < d1 || *this == d1;
	}
	bool operator>(const Date& d1) {
		return !(*this <= d1);
	}
	bool operator>=(const Date& d1) {
		return !(*this < d1);
	}
	bool operator!=(const Date& d1) {
		return !(*this == d1);
	}
	Date& operator++() {
		*this += 1;
		return *this;
	}
	Date operator++(int) {
		Date tmp = *this;
		*this += 1;
		return tmp;
	}
	int operator-(const Date& d1) const {
		int flag = 1;
		Date max = *this;
		Date min = d1;
		if (*this < d1) {
			max = d1;
			min = *this;
			flag = -1;
		}
		int n = 0;
		while (min != max) {
			++min;
			++n;
		}
		return n * flag;
	}
	/*ostream& operator<<(ostream& out) {
		out << this->_year << this->_month << this->_day << endl;
		return out;
	}*/
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& out, Date& d1) {
	cout << d1._year << d1._month << d1._day << endl;
	return out;
}
istream& operator>>(istream& in, Date& d1) {
	while (1) {
		in >> d1._year >> d1._month >> d1._day;
		if (!d1.CheckDate()) {
			cout << "·Ç·¨ÊäÈë" << endl;
			d1.Print();
		}
		else {
			break;
		}
	}
	return in;
}
int main() {
	Date d1(2025,4,23);
	Date d2 = d1;
	Date d3;
	cin >> d3;
	cout << d3;
	cout << d1;
	cout << &d1 << endl;
}
