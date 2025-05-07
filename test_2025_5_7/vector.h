#pragma once
#include <iostream>
#include <vector>

using namespace std;
namespace niuma
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				memcpy(tmp, _start, size() * sizeof(T));
				delete[] _start;
				_start = tmp;
				_finish = tmp + old_size;
				_end_of_storage = tmp + n;
			}
		}
		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}
		bool empty()
		{
			return _start == _finish;
		}
		void push_back()
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}
		void pop_back()
		{
			assert(!(empty());
			--_finish;
		}
		iterator insert(iterator pos, const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity * 2);
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}
	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};
}
template <class T>
void print_vector(const vector<T>& v)
{
	//规定没有实例化的类模板里面取东西，编译器不能区分是类型还是静态成员变量
	auto it = v.begin();
	while (it != end())
	{
		cout << *it << "";
		++it;
	}
	cout << endl;
	for (auto e : v)
	{
		cout << e << "";
	}
	cout << endl;
}
void test_vector()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	print_vector(v);
	v.insert(v.begin() + 2, 30);
	print_vector(v);
	int x;
	cin >> x;
	auto p = find(v.begin(), v.end(), x);
	if (p != v.end())
	{
		//insert 以后p就是失效，不要直接访问，要访问就要更新这个失效的迭代器
		p = v.insert(p, 40);
		(*(p + 1)) *= 10;
	}
	print_vector(v);
}