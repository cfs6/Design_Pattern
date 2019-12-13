//原型模式
#include<iostream>
#include<string>
using namespace std;
class ProtoType {
public:
	ProtoType() {
		str = "";
	}
	ProtoType(string s) {
		str = s;
	}
	virtual ~ProtoType();
	virtual ProtoType* clone() = 0;
private:
	string str;
};

class ConcreteProtoType :public ProtoType {
	ConcreteProtoType(string s) :ProtoType(s){}
	ConcreteProtoType() {}
	~ConcreteProtoType();

	ProtoType* clone() {
		ConcreteProtoType* p = new ConcreteProtoType();
		*p = *this;
		return p;
	}
};
