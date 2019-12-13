//Composite Pattern
#include<iostream>
#include<vector>
class Component {                                       //抽象构件
public:
	
	virtual ~Component() {}
	virtual void Operation() = 0;
	virtual void Add(Component*);
	virtual bool Remove(Component*);
	virtual Component* GetChild(int index)const;
protected:
	Component() {}
};

class Leaf : public Component{                          //叶子构件
public:
	Leaf() {}
	~Leaf() {}
	void Operation() {
		std::cout << "Leaf::Operation" << std::endl;
	}
};

class Composite :public Component {                     //容器构件
public:
	Composite(std::vector<Component*> mVector) { 
		ComVector = mVector;
	}
	~Composite() {

	}
	void Add(Component* comp) {
		ComVector.push_back(comp);
	}
	bool Remove(Component* comp) {
		if (ComVector.empty())
			return false;
		std::vector<Component*>::iterator it;
		for (it = ComVector.begin(); it != ComVector.end(); ++it) {
			if (*it == comp) {
				ComVector.erase(it);
				return true;
			}
		}
		return false;
	}
	Component* GetChild(int index) const{
		if ((index < 0) || (index > ComVector.size()))
			return nullptr;
		return ComVector[index - 1];
	}
private:
	std::vector<Component*> ComVector;
};