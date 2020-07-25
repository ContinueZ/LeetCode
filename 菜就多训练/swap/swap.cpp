#include<iostream>
#include<vector>

/*--------------------------类的情况------------------------------*/
class WidgetImpl {
public:
private:
	int a, b, c;
	std::vector<double> v;
};


class Widget {
public:
	Widget(WidgetImpl* p) : pImpl(p) {}
	Widget(const Widget& rhs);
	Widget& operator=(const Widget& rhs)
	{
		*pImpl = *(rhs.pImpl);
	}
	void swap(Widget& other)
	{
		using std::swap;
		swap(pImpl, other.pImpl);
	}

public:
	WidgetImpl* pImpl;
};

namespace std {
	template<>//全特化
	void swap<Widget>(Widget& a, Widget& b)
	{
		a.swap(b);
	}
}


/*-----------------------------模板实现------------------------------*/
namespace WidgetStuff {
	template<typename T>
	class WidgetImpl {
	public:
	private:
		T a, b, c;
		std::vector<double> v;
	};

	template<typename T>
	class Widget {
	public:
		Widget(WidgetImpl<T>* p) : pImpl(p) {}
		Widget(const Widget& rhs);
		Widget& operator=(const Widget& rhs)
		{
			*pImpl = *(rhs.pImpl);
		}
		void swap(Widget& other)
		{
			using std::swap;
			swap(pImpl, other.pImpl);
		}

	public:
		WidgetImpl<T>* pImpl;
	};

	template<typename T>
	void swap(Widget<T>& a, Widget<T>& b)
	{
		a.swap(b);
	}
}
/*------------------------------------------------------------------------*/
int main()
{
	WidgetStuff::WidgetImpl<int> a1;
	WidgetStuff::WidgetImpl<int> a2;

	WidgetStuff::Widget<int> w1(&a1);
	WidgetStuff::Widget<int> w2(&a2);
	std::cout << &a1 << " " << &a2 << std::endl;
	std::cout << w1.pImpl << " " << w2.pImpl << std::endl;
	using std::swap;
	swap(w1, w2);
	std::cout << &a1 << " " << &a2 << std::endl;
	std::cout << w1.pImpl << " " << w2.pImpl << std::endl;
	return 0;
}

