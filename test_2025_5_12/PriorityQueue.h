#pragma once
#include <vector>
using namespace std;
template<class T>
//ÌØ»¯	
//template<>
//class Less(Date*)
//{
//public:
//	bool operator()(Date* const& x, Date* const& y)
//	{
//		return *x < *y;
//	}
//}
class Less
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};
template <class T>
class Greater
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};
namespace niuma {
	template<class T,class Container = vector<T>,class Compare = Less<T>>
	class PriorityQueue
	{
	public:
		void AdjustUp(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0) {
				if (com(_con[child], _con[parent]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(_con.size() - 1);
		}
		void AdjustDown(int parent)
		{
			size_t child = parent * 2 + 1;
			Compare com;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					++child;
				}
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}
		const T& top()
		{
			return _con[0];
		}
		size_t size()
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
}