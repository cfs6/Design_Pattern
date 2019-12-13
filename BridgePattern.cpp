//Bridge Pattern
#include<iostream>
class Abstraction {
public:
	virtual void Operation() = 0;
	virtual ~Abstraction() {}
protected:
	Abstraction() {}
};

class RefinedAbstractionA:public Abstraction {
public:
	RefinedAbstractionA(AbstractImplement* imp) {
		this->pImp = imp;
	}
	~RefinedAbstractionA() {
		delete this->pImp;
		this->pImp = nullptr;
	}
	void Operation() {
		std::cout << "RefinedAbstractionA::operator" << std::endl;
		this->pImp->Operator();
	}

private:
	AbstractImplement* pImp;
};

class RefinedAbstractionB :public Abstraction{
public:
	RefinedAbstractionB(AbstractImplement* imp) {
		this->pImp = imp;
	}
	void Operation() {
		std::cout << "RefinedAbstractionB::operation" << std::endl;
		this->pImp->Operator();
	}
	~RefinedAbstractionB() {
		delete this->pImp;
		this->pImp = nullptr;
	}
private:
	AbstractImplement* pImp;
};

class AbstractImplement {
public:
	virtual void Operator() = 0;
	virtual ~AbstractImplement() {}

protected:
	AbstractImplement() {}
};

class ConcreteAbstractImplementA :public AbstractImplement {
public:
	ConcreteAbstractImplementA() {}
	~ConcreteAbstractImplementA() {}
	void Operator() {
		std::cout << "ConcreteAbstractImplementA::operator" << std::endl;
	}
};

class ConcreteAbstractImplementB :public AbstractImplement {
public:
	ConcreteAbstractImplementB() {}
	~ConcreteAbstractImplementB(){}
	void Operator() {
		std::cout << "ConcreteAbstractImplementB::operator" << std::endl;
	}
};