//////////////////////////////////////////////////////////////////////////////
// Goods.h
// заголовний файл Ц визначенн€ класу
#pragma once
#include "Money.h"
#include<string>
using namespace std;
class Goods
{
	string name;
	int price, quantity, no, date;

	Money money;
public:
	string GetName() const { return name; };
	int GetDate() const { return date; };
	int GetPrice() const { return price; };
	int GetQuantity() const { return quantity; };
	int GetNo() const { return no; };
	void SetName(string value) { name = value; };
	void SetDate(int value) { date = value; };
	void SetPrice(int value) { price = value; };
	void SetQuantity(int value) { quantity = value; };
	void SetNo(int value) { no = value; }
	Money GetMoney() const { return money; }
	void SetMoney(Money value)
	{
		money.SetHr(value.GetHr());
		money.SetKop(value.GetKop());
	}
	void Init(const string&, int, int, int, int);
	void Read();
	void Display();
	string toString();
	void ChangePrice(double newPriceHr, double newPriceKop);
	void PlusQuantity(int amount);
	void MinusQuantity(int amount);
	Money Cost() const;

};
