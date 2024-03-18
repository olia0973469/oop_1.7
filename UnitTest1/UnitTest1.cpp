#include "pch.h"
#include "CppUnitTest.h"
#include "../oop_1.7/Money.h"
#include "../oop_1.7/Money.cpp"
#include "../oop_1.7/Goods.h"
#include "../oop_1.7/Goods.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMoneyAddition)
		{
			Money money1;
			money1.Init(10, 50);
			Money money2;
			money2.Init(5, 25);

			Money result = money1.Add(money2);

			Assert::AreEqual(result.GetHr(), 15.0);
			Assert::AreEqual(result.GetKop(), 75.0);
		}
	};
}