//////////////////////////////////////////////////////////////////////////////
// Money.cpp
// פאיכ נואכ³חאצ³¿ – נואכ³חאצ³ÿ לועמה³ג ךכאסף

#include "Money.h"
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

void Money::Display() const
{
	cout << endl;
	cout << " Hryvni = " << hr << endl;
	cout << " Kopijky = " << kop << endl;
}

void Money::Init(double x, double y)
{
	hr = x;
	kop = y;
}

void Money::Read()
{
	double x, y;
	cout << "Input money:" << endl;
	cout << " Hryvni = "; cin >> x;
	cout << " Kopijky = "; cin >> y;
	Init(x, y);
}

string Money::toString() const
{
	stringstream sout; 
	sout << hr << " UAH, Kop ";
	sout << kop;
	return sout.str();
}

Money Money::Add(const Money& other) const
{
	Money result;
	result.hr = this->hr + other.hr;
	result.kop = this->kop + other.kop;

	if (result.kop >= 100)
	{
		result.hr += result.kop / 100;
		result.kop = 100;
	}

	return result;
}

Money Money::Sub(const Money& other) const
{
	Money result;
	result.hr = this->hr - other.hr;
	result.kop = this->kop - other.kop;

	if (result.kop >= 100)
	{
		result.hr -= result.kop / 100;
		result.kop = 100;
	}

	return result;
}

double Money::Divide(const Money& other) const
{
	if (other.hr == 0 || other.kop == 0)
	{
		std::cout << "Error: Division by zero" << std::endl;
		return 0.0;
	}

	double totalThis = hr - (static_cast<double>(kop) / 100);
	double totalOther = other.hr - (static_cast<double>(other.kop) / 100);

	return totalThis / totalOther;
}

Money Money::DivideFraction(double division)
{
	if (division == 0.0)
	{
		cerr << "Error.\n";
		exit(1);
	}
	Money result;
	result.hr = this->hr / division;
	result.kop = this->kop / division;
	return result;
}

Money Money::MultFraction(double mult)
{
	Money result;
	result.hr = this->hr * mult;
	result.kop = this->kop * mult;
	return result;
}

bool Money::operator==(const Money& other) const
{
	return (hr == other.hr) && (kop == other.kop);
}

bool Money::operator!=(const Money& other) const
{
	return !(*this == other);
}

bool Money::operator<(const Money& other) const
{
	double totalThis = hr + (static_cast<double>(kop) / 100);
	double totalOther = other.hr + (static_cast<double>(other.kop) / 100);
	return totalThis < totalOther;
}

bool Money::operator<=(const Money& other) const
{
	return (*this < other) || (*this == other);
}

bool Money::operator>(const Money& other) const
{
	return !(*this <= other);
}

bool Money::operator>=(const Money& other) const
{
	return !(*this < other);
}

void Money::Discount(double percentage)
{
	double discount = (percentage / 100) * (hr + (static_cast<double>(kop) / 100));
	hr -= static_cast<int>(discount);
	kop -= static_cast<int>((discount - floor(discount)) * 100);

	while (kop < 0)
	{
		hr--;
		kop += 100;
	}

	if (hr < 0)
	{
		cerr << "Error: Negative price after discount!" << endl;
		exit(1);
	}
}
