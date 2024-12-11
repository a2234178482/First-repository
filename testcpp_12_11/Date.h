#pragma once
#include<iostream>
using namespace std;
#include<assert.h>

class Date
{
	// Ԫ
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	bool CheckDate() const;
	Date(int year = 1900, int month = 1, int day = 1);
	void Print() const;

	// Ĭinline
	int GetMonthDay(int year, int month) const
	{
		assert(month > 0 && month < 13);

		static int monthDayArray[13] = { -1, 31, 28, 31, 30, 31, 30,
31, 31, 30, 31, 30, 31 };

		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}

		return monthDayArray[month];
	}

	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	Date operator+(int day) const;
	Date& operator+=(int day);

	Date operator-(int day) const;
	Date& operator-=(int day);

	// d1++;
	// d1.operator++(0);
	Date operator++(int);

	// ++d1;
	// d1.operator++();
	Date& operator++();

	// d1--;
	// d1.operator--(0);
	Date operator--(int);

	// --d1;
	// d1.operator--();
	Date& operator--();

	// d1 - d2
	int operator-(const Date& d) const;

	//void operator<<(ostream& out);

	Date* operator&()
	{
		//return this;
		//return nullptr;
		return (Date*)0x2673FF40;
	}

	const Date* operator&() const
	{
		//return this;
		//return nullptr;
		return (Date*)0x2673FE30;
	}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);