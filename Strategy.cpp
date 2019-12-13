//Strattegy Pattern
#include<iostream>
class Strategy {
public:
	Strategy() {}
	virtual ~Strategy() {}
	virtual void AlgFunc() = 0;
};

class ConcreteStrategy1 : public Strategy {
public:
	ConcreteStrategy1() {}
	~ConcreteStrategy1() {}

	void AlgFunc() {
		std::cout << "ConcreteStrategy1::AlgFunc()" << std::endl;
	}

};
class ConcreteStrategy2 : public Strategy {
public:
	ConcreteStrategy2() {}
	~ConcreteStrategy2() {}

	void AlgFunc() {
		std::cout << "ConcreteStrategy2::AlgFunc()" << std::endl;
	}

};

class Context {
public:
	Context(Strategy* strategy) :m_Strategy(strategy) {}
	~Context() {
		delete m_Strategy;
		m_Strategy = nullptr;
	} 

	void func() {
		m_Strategy->AlgFunc();
	}
private:
	Strategy* m_Strategy;
};