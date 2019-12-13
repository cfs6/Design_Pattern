//Proxy pattern
#include<iostream>

class AbstractSubject {                                        //抽象主题角色
public:
	AbstractSubject() {}

	virtual void Request() = 0;
};

class ConcreteSubject :public AbstractSubject{                         //具体主题角色
public:
	void Request() {
		std::cout << "ConcreteSubject::Request()" << std::endl;
	}
};

class Proxy0 :public AbstractSubject {                         //代理角色0
public:
	Proxy0() {
		pAbstractSubject0 = new ConcreteSubject();
	}
	Proxy0(AbstractSubject* AbstractSubject) {
		pAbstractSubject0 = AbstractSubject;
	}
	~Proxy0() {
		delete pAbstractSubject0;
		pAbstractSubject0 = nullptr;
	}
	void Request() {
		this->pAbstractSubject0->Request();
		std::cout << "Proxy0::Request()" << std::endl;
	}

	void AddedRequest() {
		
		std::cout << "Proxy0::AddedRequest()" << std::endl;
	}

private:
	AbstractSubject* pAbstractSubject0;
};

class Proxy1 :public AbstractSubject {                          //代理角色1
public:
	Proxy1() {
		pConcreteSubject1 = new ConcreteSubject();
	}
	Proxy1(AbstractSubject* AbstractSubject) {
		pConcreteSubject1 = AbstractSubject;
	}
	~Proxy1() {
		delete pConcreteSubject1;
		pConcreteSubject1 = nullptr;
	}
	void Request() {
		this->pConcreteSubject1->Request();
		std::cout << "Proxy1::Request()" << std::endl;
	}

	void AddedRequest() {
		std::cout << "Proxy1::AddedRequest()" << std::endl;
	}

private:
	AbstractSubject* pConcreteSubject1;
};

int main() {
	ConcreteSubject* pConSub = new ConcreteSubject();
	pConSub->Request();
	Proxy0* pProxy0 = new Proxy0();
	Proxy1* pProxy1 = new Proxy1();

	pProxy0->Request();
	pProxy0->AddedRequest();
	pProxy1->Request();
	pProxy1->AddedRequest();
	system("pause");
	return 0;
}
