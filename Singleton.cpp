#include<iostream>
template<typename T>
class Singleton {
public:
	template<typename... Args>
	static T* instance(Args&&... args)
	{
		if (singletonInstance == nullptr)
		{
			singletonInstance = new T(std::forward<T>(args)...);
		}
		return singletonInstance;
	}

	static T* getInstance()const
	{
		if (singletonInstance == nullptr)
		{
			throw std::logic_error("singletonInstance == nullptr");
		}
		return singletonInstance;
	}

	static void deleteInstance()
	{
		delete singletonInstance;
		singletonInstance = nullptr;
	}
private:
	Singleton();
	virtual ~Singleton();
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

private:
	static T* singletonInstance;
};