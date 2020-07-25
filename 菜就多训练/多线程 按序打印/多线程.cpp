#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

class Foo {
public:
	Foo() {

	}

	void first(function<void()> printFirst) {

		// printFirst() outputs "first". Do not change or remove this line.
		std::unique_lock<mutex> sbgurad1(g_mutex);
		printFirst();
		counter++;
		cv1.notify_one();
	}

	void second(function<void()> printSecond) {

		// printSecond() outputs "second". Do not change or remove this line.
		std::unique_lock<mutex> sbgurad1(g_mutex);
		cv1.wait(sbgurad1, [this] {
			return counter == 2;
		});
		printSecond();
		counter++;
		cv2.notify_one();
	}

	void third(function<void()> printThird) {

		// printThird() outputs "third". Do not change or remove this line.
		std::unique_lock<mutex> sbgurad1(g_mutex);
		cv2.wait(sbgurad1, [this] {
			return counter == 3;
		});
		printThird();
	}
private:
	std::mutex g_mutex;
	condition_variable cv1;
	condition_variable cv2;
	int counter = 1;
};

class FooBar {
private:
	int n;
	bool var = true;
	mutex m_mutex;
	condition_variable cv1;
	condition_variable cv2;
public:
	FooBar(int n) {
		this->n = n;
	}

	void foo(function<void()> printFoo) {

		std::unique_lock<mutex> sbguard(m_mutex);
		for (int i = 0; i < n; i++) {

			// printFoo() outputs "foo". Do not change or remove this line.
			
			cv2.wait(sbguard, [this] {
				return var;
			});
			printFoo();
			var = false;
			cv1.notify_one();
		}
	}

	void bar(function<void()> printBar) {

		std::unique_lock<mutex> sbguard(m_mutex);
		for (int i = 0; i < n; i++) {

			// printBar() outputs "bar". Do not change or remove this line.
			
			cv1.wait(sbguard, [this] {
				return	!var;
			});
			printBar();
			var = true;
			//sbguard.unlock();
			cv2.notify_one();
		}
	}
};

class ZeroEvenOdd {
private:
	int n;
	bool bzero;
	bool bodd;
	std::mutex m_mutex;
	condition_variable cv_zero;
	condition_variable cv_even;
	condition_variable cv_odd;
public:
	ZeroEvenOdd(int n) {
		this->n = n;
		bzero = true;
	}

	// printNumber(x) outputs "x", where x is an integer.
	void zero(function<void(int)> printNumber) {

		std::unique_lock<std::mutex> sbguard(m_mutex);
		for (int i = 1; i <= n; i++)
		{

			cv_zero.wait(sbguard, [this] {
				return bzero;
			});
			printNumber(0);
			bzero = false;
			if (i % 2)
			{
				bodd = true;
				cv_odd.notify_one();
			}
			else
			{
				bodd = false;
				cv_even.notify_one();
			}
		}


	}

	void even(function<void(int)> printNumber) {
		for (int i = 1; 2 * i <= n; i++)
		{
			std::unique_lock<std::mutex> sbguard(m_mutex);
			cv_even.wait(sbguard, [this] {
				return !bodd && !bzero;
			});
			printNumber(2 * i);
			bzero = true;
			cv_zero.notify_one();
		}
	}

	void odd(function<void(int)> printNumber) {
		for (int i = 0; 2 * i + 1 <= n; i++)
		{
			std::unique_lock<std::mutex> sbguard(m_mutex);
			cv_odd.wait(sbguard, [this] {
				return bodd && !bzero;
			});
			printNumber(2 * i + 1);
			bzero = true;
			cv_zero.notify_one();
		}
	}
};

class H2O {
public:
	H2O():m_iCountH(0),m_iCountO(0){

	}

	void hydrogen(function<void()> releaseHydrogen) {

		// releaseHydrogen() outputs "H". Do not change or remove this line.
		std::unique_lock<mutex> sbguard(m_mutex);
			cv.wait(sbguard, [this] {
				return m_iCountH % 2 != 0 || m_iCountH == 2 * m_iCountO;
		});
		releaseHydrogen();
		m_iCountH++;
		cv.notify_all();
	}

	void oxygen(function<void()> releaseOxygen) {

		// releaseOxygen() outputs "O". Do not change or remove this line.

		std::unique_lock<mutex> sbguard(m_mutex);
		cv.wait(sbguard, [this] {
			return (m_iCountH % 2 == 0 && m_iCountH == 2 * m_iCountO + 2)
				|| (m_iCountH % 2 != 0 && m_iCountH == 2 * m_iCountO + 1);
		});
		releaseOxygen();
		m_iCountO++;
		cv.notify_all();
	}

private:
	int m_iCountH;
	int m_iCountO;

	std::mutex m_mutex;
	condition_variable cv;
};