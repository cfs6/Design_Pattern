#include<iostream>
#include<mutex>
#include<thread>
class Singleton {

public:
	static Singleton* GetInstance() {
		if (instance == nullptr) {
			std::lock_guard<std::mutex> locker(m_mutex);
			instance = new Singleton();
		}
		return instance;
	}
	static void DestroyInstance() {
		if (instance != nullptr) {
			std::lock_guard<std::mutex> locker(m_mutex);
			delete instance;
		}
		instance = nullptr;
	}
private:
	Singleton() {};
	static Singleton* instance;
	static std::mutex m_mutex;
};