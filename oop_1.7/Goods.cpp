//////////////////////////////////////////////////////////////////////////////
// Goods.cpp
// файл реалізації – реалізація методів класу

#include "Goods.h"
#include <iostream>
#include <string>

using namespace std;

void Goods::Init(const string& n, int d, int q, int x, int y)
{
	name = n;
	date = d;
	quantity = q;
	money.Init(x, y);
}

void Goods::Read()
{
	cout << "Enter name: "; cin >> name;
	cout << "Enter date: "; cin >> date;
	cout << "Enter quantity: "; cin >> quantity;
	money.Read(); // використовуємо делегування
}

void Goods::Display()
{
	cout << "Name: " << name << endl;
	cout << "Date: " << date << endl;
	cout << "Quantity: " << quantity << endl;
	cout << "Price: " << money.toString() << endl;
	money.Display(); // використовуємо делегування
}

void Goods::ChangePrice(double newPriceHr, double newPriceKop) 
{
	money.SetHr(newPriceHr);
	money.SetKop(newPriceKop);
}

void Goods::PlusQuantity(int amount) 
{
	quantity += amount;
}

void Goods::MinusQuantity(int amount) 
{
	quantity -= amount;
	if (quantity < 0)
		quantity = 0;
}

Money Goods::Cost() const 
{
    double total = money.GetHr() + (money.GetKop() / 100);
    total *= quantity;

    Money result;
    result.SetHr(floor(total));
    result.SetKop((total - floor(total)) * 100);

    return result;
}

string Goods::toString() 
{
	return Cost().toString();
}
