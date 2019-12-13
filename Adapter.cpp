//Adapter Pattern
#include<iostream>
using namespace std;

class Target {                                      //抽象适配器
public:
	Target() {}
	virtual ~Target() {}
	virtual void Request() {
		cout << "Target request" << endl;
	}
};

class Adaptee {
public:
	Adaptee() {}
	~Adaptee() {}
	void SpecificRequest() {
		cout << "Adaptee::SpecificRequest" << endl;
	}
};
//类模式，适配器类，通过public继承获得接口继承的效果，通过private继承获得实现继承的效果
class Adapter1 :public Target, private Adaptee {                    //具体适配器
public:
	Adapter1() {}
	~Adapter1() {}
	void Request(){
		cout << "Adapter::Request" << endl;
		this->SpecificRequest();
		cout << "-----------------" << endl;
	}

};

//对象模式，适配器类，继承Target类，采用组合的方式实现Adaptee的复用
class Adapter2 :public Target {                                     //具体适配器
public:
	Adapter2() :m_adaptee(new Adaptee()) {}
	Adapter2(Adaptee* adaptee) :m_adaptee(adaptee) {}

	~Adapter2() {}
	void Request(Adaptee* adaptee) {
		cout << "Adapter::request" << endl;
		this->m_adaptee->SpecificRequest();
		cout << "---------------" << endl;
	}
private:
	Adaptee* m_adaptee;
};

int main() {
	Target* pTarget = new Adapter1();
	pTarget->Request();

	Adaptee* pAdaptee = new Adaptee();
	Target* pt1 = new Adapter1();
	Adapter1* mAdapter1 = new Adapter1();

	Adaptee* pAdaptee = new Adaptee();
	Target* pTarget2 = new Adapter2(pAdaptee);
	pTarget->Request();

	return 0;
}