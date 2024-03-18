//////////////////////////////////////////////////////////////////////////////
// Money.h
// заголовний файл Ц визначенн€ класу

#pragma once
#include <string>
using namespace std;
class Money
{
	double hr;
	double kop;
public:
	double GetHr() const { return hr; }
	double GetKop() const { return kop; }
	void SetHr(double value) { hr = value; }
	void SetKop(double value) { kop = value; }
	void Init(double, double);
	void Read();
	void Display() const;
	string toString() const;
	Money Add(const Money& other) const;
	Money Sub(const Money& other) const;
	double Divide(const Money& other) const;
	Money DivideFraction(double division);
	Money MultFraction(double mult);
	bool operator==(const Money& other) const;
	bool operator!=(const Money& other) const;
	bool operator<(const Money& other) const;
	bool operator<=(const Money& other) const;
	bool operator>(const Money& other) const;
	bool operator>=(const Money& other) const;
	void Discount(double percentage);
};
