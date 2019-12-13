//Template Pattern
#include<iostream>

class AbstractClass {
public:
	AbstractClass() {}
	virtual ~AbstractClass() {}
	void PrimitiveOperation1() {                              //���巽��
		std::cout << "PrimitiveOperation1()" << std::endl;
	}

	virtual void PrimitiveOperation2() = 0;                   //���󷽷�
	void templatemethod() {
		this->PrimitiveOperation1();
		this->PrimitiveOperation2();
	}
};

class ConcreteClass1 : public AbstractClass{
public:
	ConcreteClass1() {}
	~ConcreteClass1() {}
	void PrimitiveOperation2() {
		std::cout << "ConcreteClass1::Operation()" << std::endl;
	}
};

