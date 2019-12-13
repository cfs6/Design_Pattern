//Decorator Pattern
#include<iostream>

class Component {
public:
	Component() {}
	virtual ~Component(){}
	virtual void operation()=0;
};

class ConcreteComponent :public Component{
public:
	ConcreteComponent() {}
	~ConcreteComponent() {}
	void operation() {
		std::cout << "ConcreteComponent::operation" << std::endl;
	}
};

class Decorator :public Component{
public:
	Decorator() {}
	Decorator(Component* comp) {
		m_Component = comp;
	}
	virtual ~Decorator() {}
	virtual void operation() {
//		std::cout << "Decorator::operation" << std::endl;
		m_Component->operation();
	}
	

protected:
	Component* m_Component;
};

class ConcreteDecorator : public Decorator{
public:
	ConcreteDecorator(Component* comp){
		m_Component = comp;
	}
	~ConcreteDecorator() {}
	void AddedBehavior() {
		std::cout << "AddedBehavior" << std::endl;
	}
};

int main() {
	Component* pCom = new ConcreteComponent();
	ConcreteDecorator* pDeco = new ConcreteDecorator(pCom);
	pDeco->operation();
	pDeco->AddedBehavior();

	system("pause");
	return 0;
}