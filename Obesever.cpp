#include<functional>
#include<unordered_map>
#include<string>
using namespace std;
class NonCopyable {
	NonCopyable() = default;
	~NonCopyable() = default;
	NonCopyable(const NonCopyable& rhs) = delete;
	NonCopyable& operator=(const NonCopyable& rhs) = delete;
};

template<typename Func>
class Observer :NonCopyable
{
public:
	Observer() {}
	~Observer() {}

	int add(Func &f)
	{
		return assign(f);
	}

	int add(Func &&f)
	{
		return assign(f);
	}

	void remove(int &&f)
	{
		ObeseverMap.erase(f);
	}
	
	template<typename... Args>
	void Notify(Args&&... args)
	{
		for (auto it : ObeseverMap)
		{
			it.second(forward<Args>(args)...);
		}
	}

private:
	template<typename F>
	int assign(F &&f)
	{
		int k = ObeserverId++;
		ObeseverMap.emplace(k, f);
		return k;
	}

	static int ObeserverId = 0;
	unordered_map<int, Func> ObeseverMap;
};

