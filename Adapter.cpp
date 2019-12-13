//Adapter Pattern
#include<iostream>
using namespace std;

class Target {                                      //����������
public:
	Target() {}
	virtual ~Target() {}
	virtual void Request() {
		cout << "Target request" << endl;
	}
};

class Adaptee {
public:
	Adaptee() {}
	~Adaptee() {}
	void SpecificRequest() {
		cout << "Adaptee::SpecificRequest" << endl;
	}
};
//��ģʽ���������࣬ͨ��public�̳л�ýӿڼ̳е�Ч����ͨ��private�̳л��ʵ�ּ̳е�Ч��
class Adapter1 :public Target, private Adaptee {                    //����������
public:
	Adapter1() {}
	~Adapter1() {}
	void Request(){
		cout << "Adapter::Request" << endl;
		this->SpecificRequest();
		cout << "-----------------" << endl;
	}

};

//����ģʽ���������࣬�̳�Target�࣬������ϵķ�ʽʵ��Adaptee�ĸ���
class Adapter2 :public Target {                                     //����������
public:
	Adapter2() :m_adaptee(new Adaptee()) {}
	Adapter2(Adaptee* adaptee) :m_adaptee(adaptee) {}

	~Adapter2() {}
	void Request(Adaptee* adaptee) {
		cout << "Adapter::request" << endl;
		this->m_adaptee->SpecificRequest();
		cout << "---------------" << endl;
	}
private:
	Adaptee* m_adaptee;
};

int main() {
	Target* pTarget = new Adapter1();
	pTarget->Request();

	Adaptee* pAdaptee = new Adaptee();
	Target* pt1 = new Adapter1();
	Adapter1* mAdapter1 = new Adapter1();

	Adaptee* pAdaptee = new Adaptee();
	Target* pTarget2 = new Adapter2(pAdaptee);
	pTarget->Request();

	return 0;
}