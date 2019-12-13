//Observer Pattern
#include<iostream>
#include<list>
class Object {
public:
	Object() {}
	virtual ~Object() {}
	virtual void Attach(Observer* pObserver) = 0;
	virtual void Detach(Observer* pObserver) = 0;
	virtual void Notify() = 0;

};
class Observer {
public:
	Observer() {}
	virtual ~Observer() {}
	virtual void Update() = 0;
};

class ConcreteObserver :public Observer {
public:
	ConcreteObserver(Object* object) {
		m_Object = object;
	}
	~ConcreteObserver() {
		delete m_Object;
		m_Object = nullptr;
	}
	void Update() {
		std::cout << "Update Observer" << std::endl;
	}
private:
	Object* m_Object;
};

class ConcreteObserver2 :public Observer {
public:
	ConcreteObserver2(Object* object) {
		m_Object = object;
	}
	~ConcreteObserver2() {
		delete m_Object;
		m_Object = nullptr;
	}
	void Update() {
		std::cout << "Update ConcreteObserver2" << std::endl;
	}
private:
	Object* m_Object;
};

class ConcreteObject :public Object {
public:
	ConcreteObject() {}
	~ConcreteObject() {}
	void Attach(Observer* pObserver) {
		m_ObserverList.push_back(pObserver);
	}
	void Deteach(Observer* pObserver) {
//		std::list<Observer*>::iterator it;
//		for (it = m_ObserverList.begin(); it != m_ObserverList.end(); ++it) {
//			if (*it == pObserver) {
//				m_ObserverList.erase(it);
//			}
//		}
		m_ObserverList.remove(pObserver);
	}

	void Notify() {
		for (auto r : m_ObserverList) {
			r->Update();
		}
	}
private:
	std::list<Observer*> m_ObserverList;

};