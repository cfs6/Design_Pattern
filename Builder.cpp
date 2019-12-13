//������ģʽ
//KFC�ײ�ʵ��
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
		meal->SetFood("һ�����ȱ�");
	}
	void BuildDrink() {
		meal->SetDrink("һ������");
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
		meal->SetFood("һ�������");
	}
	void BuildDrink() {
		meal->SetDrink("һ����֭");
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
