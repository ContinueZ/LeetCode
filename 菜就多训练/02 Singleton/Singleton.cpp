#include <iostream>
#include <mutex>

std::mutex m_mutex;
class Singleton
{
public:
	static Singleton* GetInstance();

	class reSingleton {
	public:
		~reSingleton() {
			if (m_pInstance != nullptr)
			{
				delete m_pInstance;
				m_pInstance = nullptr;
			}
		}
	};
private:
	Singleton() {

	}
private:
	static Singleton *m_pInstance;
	
};

Singleton* Singleton::m_pInstance = nullptr;

Singleton* Singleton::GetInstance()
{
	if (m_pInstance == nullptr)
	{
		std::unique_lock<std::mutex> sbguard(m_mutex);
		if (m_pInstance == nullptr)
		{
			m_pInstance = new Singleton();
			std::cout << "单例模式创建成功！\n";
			static reSingleton cl;
		}	
	}
	else
	{
		std::cout << "只能创建一个实例！\n";
	}
	return m_pInstance;
}

int main()
{
	Singleton * s1 = Singleton::GetInstance();
	Singleton * s2 = Singleton::GetInstance();
}