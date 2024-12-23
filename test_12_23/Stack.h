#pragma once
#include<deque>
//
//template<class T>
//class stack
//{
//private:
//	T* _a;
//	size_t _top;
//	size_t _capacity;
//};

namespace bit
{
	// Containerתstack
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		const T& top() const
		{
			//return _con.func();
			return _con.back();
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}

	private:
		Container _con;
	};

	/*void func()
	{
		cout << "void func()" << endl;
	}*/
}