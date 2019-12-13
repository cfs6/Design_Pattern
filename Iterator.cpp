//Iterator Pattern
#include<iostream>
#include<vector>
template<typename T>
class Iterator {
public:
	Iterator() {}
	virtual ~Iterator() {}
	virtual T First() = 0;
	virtual T Next() = 0;
	virtual T GetCur() = 0;
	
//	virtual bool HasNext() = 0;
};



template<typename T>
class ConcreteIterator :public Iterator<T> {
public:
	ConcreteAggregate(Aggregate<T>* aggregate) {
		m_Aggregate = aggregate;
	}
	~ConcreteAggregate() {}
	T First() {
		return m_Aggregate->Pop(0);
	}
	T Next() {
		++cur;
		if (cur < m_Aggregate) {
			return m_Aggregate->pop(cur);
		}
		else
			return nullptr;
	}
	T GetCur() {
		return m_Aggregate->cur;
	}

private:
	Aggregate<T>* m_Aggregate;
	T cur;
};

template<typename T>
class Aggregate {
public:
	Aggregate() {}
	~Aggregate() {}
	virtual void Push(const T item) = 0;
	virtual T Pop(const T item) = 0;
	virtual int Count() = 0;
	virtual Iterator<T>* CreateIterator() = 0;
};

template<typename T>
class ConcreteAggregate :public Aggregate<T> {
public:
	ConcreteAggregate() {}
	~ConcreteAggregate() {}
	void Push(const T item) {
		data.push_back(item);
	}

	T Pop(const T item) {
		for (auto r : data) {
			if (r == item) {
				data.erase(r);
			}
		}
	}

	int Count() {
		return data.size();
	}

	Iterator<T>* CreateIterator() {
		return new ConcreteIterator;
	}
private:
	std::vector<T> data;
};