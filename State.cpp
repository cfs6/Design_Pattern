//State Pattern
#include<iostream>
class Context;
class State {
public:
	State() {}
	virtual ~State() {}
	virtual void Handle(Context* context) = 0;
};

class ConcreteState :public State {
public:
	ConcreteState() {}
	ConcreteState(Context* context) {
		m_Context = context;
	}
	~ConcreteState() {
		delete m_Context;
		m_Context = nullptr;
	}

	void Handle(Context* context) {
		std::cout << "ConcreteState::Handle" << std::endl;
	}

private:
	Context* m_Context;
};

class ConcreteState2 :public State {
public:
	ConcreteState2() {}
	ConcreteState2(Context* context) {
		m_Context = context;
	}
	~ConcreteState2() {
		delete m_Context;
		m_Context = nullptr;
	}

	void Handle(Context* context) {
		std::cout << "ConcreteState2::Handle" << std::endl;
	}

private:
	Context* m_Context;
};

class Context {
public:
	Context(State* pConcreteState) :m_ConcreteState(pConcreteState) {}
	~Context() {
		delete m_ConcreteState;
		m_ConcreteState = nullptr;
	}

	void Request() {
		m_ConcreteState->Handle(this);
	}

	void SetState(State* pConcreteState) {
		m_ConcreteState = pConcreteState;
	}
private:
	State* m_ConcreteState;
};

int main() {


	State* pState1 = new ConcreteState();
	State* pState2 = new ConcreteState2();

	Context* pContext = new Context(pState1);

	pContext->Request();
	pContext->SetState(pState2);
	pContext->Request();

	system("pause");
	return 0;
}