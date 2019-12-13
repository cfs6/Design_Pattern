//Facade Pattern
#include<iostream>
class SubSystemA {
public:
	SubSystemA() {}
	~SubSystemA() {}
	void operation() {
		std::cout << "SubSystemA::operation" << std::endl;
	}
};

class SubSystemB {
public:
	SubSystemB() {}
	~SubSystemB() {}
	void operation() {
		std::cout << "SubSystemB::operation" << std::endl;
	}
};

class Facade {
public:
	Facade() {
		SubSA = new SubSystemA();
		SubSB = new SubSystemB();
	}
	~Facade() {
		delete SubSA;
		delete SubSB;
		SubSA = nullptr;
		SubSB = nullptr;
	}
	void operation() {
		SubSA->operation();
		SubSB->operation();
	}
private:
	SubSystemA* SubSA;
	SubSystemB* SubSB;
};