//创建者模式
//KFC套餐实例
#include<iostream>
#include<string>
using namespace std;
class Meal {                                      //class Product
public:
	Meal();
	~Meal();
	void SetFood(string food) {
		food = food;
	}
	void SetDrink(string drink) {
		drink = drink;
	}

	string GetFood() {
		return food;
	}
	string GetDrink() {
		return drink;
	}
private:
	string food;
	string drink;
};

class MealBuilder {                              //Abstract builder
public:
	MealBuilder();
	virtual ~MealBuilder();

public:
	virtual void CreateMeal() = 0;
	virtual void BuildFood() = 0;
	virtual void BuildDrink() = 0;

	virtual Meal* GetMeal() = 0;

	Meal* meal;
};

class SubMealBuilderA :public MealBuilder {       //Concrete Builder A
public:
	SubMealBuilderA();
	~SubMealBuilderA();

	void CreateMeal() {
		meal = new Meal();
	}
	void BuildFood() {
		meal->SetFood("一个鸡腿堡");
	}
	void BuildDrink() {
		meal->SetDrink("一杯可乐");
	}
	Meal* GetMeal() {
		return meal;
	}
};

class SubMealBuilderB :public MealBuilder {        //Concrete Builder B
public:
	SubMealBuilderB();
	~SubMealBuilderB();

	void CreateMeal() {
		meal = new Meal();
	}
	void BuildFood() {
		meal->SetFood("一个鸡肉卷");
	}
	void BuildDrink() {
		meal->SetDrink("一杯果汁");
	}
	Meal* GetMeal() {
		return meal;
	}
};

class KFCWaiter {                                           //Director
public:
	KFCWaiter(MealBuilder* mb) {
		mb = mb;
	}
	~KFCWaiter();
	void Construct() {
		mb->BuildFood();
		mb->BuildDrink();
	}

private:
	MealBuilder* mb;
};
