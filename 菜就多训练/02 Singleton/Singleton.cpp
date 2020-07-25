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
			std::cout << "����ģʽ�����ɹ���\n";
			static reSingleton cl;
		}	
	}
	else
	{
		std::cout << "ֻ�ܴ���һ��ʵ����\n";
	}
	return m_pInstance;
}

int main()
{
	Singleton * s1 = Singleton::GetInstance();
	Singleton * s2 = Singleton::GetInstance();
}