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
		vector() = default; //强制生成默认构造函数
		vector(const vector<T>& v)
		{
			reserve(v.size());
			for (auto& e : v)
			{
				push_back(e);
			}
		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		vector(int n, const T& val = T())
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		void clear()
		{
			_finish = _start;
		}
		vector<T>& operator=(const vector<T>& v)
		{
			if (this != &v)
			{
				clear();
				reserve(v.size());
				for (auto& e : v)
				{
					push_back(e);
				}
			}
			return *this;
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}
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
		void resize(size_t n, T val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
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
		void push_back(const T& x)
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
		void erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);
			iterator it = pos + 1;
			while (it != end())
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish;
		}
		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}
		const T& operator[](size_t i) const
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
template <class Container>
void print_container(const Container& v)
{
	auto it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test_vector1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << "";
	}
	cout << endl;
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << endl;
		++it;
	}
	cout << endl;
	print_vector(v);
	vector<double> vd;
	vd.push_back(1.1);
	vd.push_back(2.2);
	vd.push_back(3.3);
	vd.push_back(4.4);
	vd.push_back(5.5);
	print_container(vd);
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
	print_container(v);
}
void test_vector2()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	print_container(v);
	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
		{
			++it;
		}
	}
	print_container(v);
}
void test_vector3()
{
	int  i = int();
	int j = int(1);
	int k(2);
	vector<int> v;
	v.resize(10, 1);
	v.reserve(20);
	print_container(v);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.resize(15, 2);
	print_container(v);
	v.resize(25, 3);
	print_container(v);
	v.resize(5);
}
