//ChainOfResponsibility 
#include<iostream>

class Handler {
public:
	Handler(int quest){pQuest = quest; }
	virtual ~Handler() {}
	void SetSuccessor(Handler* succ) {
		successor = succ;
	}
	virtual void HandleRequest(int request) = 0;
protected:
	Handler* successor;
	int pQuest;
};

class ConcreteHandlerA :public Handler{
public:
	ConcreteHandlerA(int quest) :Handler(quest) {}
	void HandleRequest(int request) {
		if (request == 1) {
			std::cout << "ConcreteHandlerA::HandleRequest" << std::endl;
		}
		else {
			if (successor != nullptr) {
				this->successor->HandleRequest(request);
			}
		}
	}
};

class ConcreteHandlerB :public Handler {
public:
	ConcreteHandlerB(int quest) :Handler(quest) {}
	void HandleRequest(int request) {
		if (request == 2) {
			std::cout << "ConcreteHandlerB::HandleRequest" << std::endl;
		}
		else {
			if (successor != nullptr) {
				successor->HandleRequest(request);
			}
		}
	}
};

int main() {
	int request1 = 1;
	int request2 = 2;

	Handler* handlerA = new ConcreteHandlerA(request1);
	Handler* handlerB = new ConcreteHandlerB(request2);

	handlerA->SetSuccessor(handlerB);

	handlerA->HandleRequest(request1);
	std::cout << std::endl;
	handlerA->HandleRequest(request2);
	system("pause");
	return 0;
}