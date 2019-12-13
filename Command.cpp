//Command Pattern
#include<iostream>
class Receiver {
public:
	Receiver() {}
	virtual ~Receiver() {}
	void Action() {
		std::cout << "Receiver::Action" << std::endl;
	}
};

class Command {
public:
	Command() {}
	virtual ~Command() {}
	virtual void Execute() = 0;
};

class ConcreteCommand :public Command{
public:
	ConcreteCommand(Receiver* receiver) {
		m_Receiver = receiver;
	}
	~ConcreteCommand() {}
	void Execute() {
		m_Receiver->Action();
	}
private:
	Receiver* m_Receiver;
};

class invoker {
public:
	void SetCommand(Command* command) {
		m_command = command;
	}

	void call() {
		m_command->Execute();
	}
private:
	Command* m_command;
};

