#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<exception>
using namespace std;
double Divide(int a, int b)
{
	try {
		if (b == 0)
		{
			string s("Divide by zero condition!");
			throw s;	
			cout << __FUNCTION__ << ":" << __LINE__ << endl;
		}
		else
		{
			return ((double)a / (double)b);
		}
	}
	catch (int errid)
	{
		cout << errid << endl;
	}
	return 0;
}
//void func()
//{
//	int len, time;
//	cin >> len >> time;
//	try
//	{
//		cout << Divide(len, time) << endl;
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	cout << __FUNCTION__ << ":" << __LINE__ << endl;
//}
//int main()
//{
//	while (1)
//	{
//		try {
//			func();
//		}
//		catch (const char* errmsg)
//		{
//			cout << errmsg << endl;
//		}
//		catch (...)
//		{
//			cout << "未知异常" << endl;
//		}
//	}
//	return 0;
//}
#include <thread>
//一般大型项目程序才会使用异常
//下面模拟设计一个服务的几个模块
//每个模块的继承都是Exception的派生类，每个模块可以添加自己的数据
//最后捕获时，我们捕获基类就行
class Exception
{
public:
	Exception(const std::string& errmsg, int id)
		:_errmsg(errmsg)
		,_id(id)
	{}
	virtual string what() const
	{
		return _errmsg;
	}
	int getid() const
	{
		return _id;
	}
protected:
	std::string _errmsg;
	int _id;
};
class SqlException : public Exception
{
public:
	SqlException(const string& errmsg, int id, const string& sql)
		:Exception(errmsg, id)
		,_sql(sql)
	{ }
	virtual string what() const
	{
		string str = "SqlException";
		str += _errmsg;
		str += "->";
		str += _sql;
		return str;
	}
private:
	const string _sql;
};

class CacheException : public Exception
{
public:
	CacheException(const string& errmsg, int id)
		:Exception(errmsg, id)
	{}
	virtual string what() const
	{
		string str = "CacheException";
		str += _errmsg;
		return str;
	}
};

class HttpException : public Exception
{
public:
	HttpException(const string& errmsg, int id, const string& type)
		:Exception(errmsg,id)
		,_type(type)
	{}
	virtual string what() const
	{
		string str = "HttpException";
		str += _type;
		str += ":";
		str += _errmsg;
		return  str;
	}
private:
	const string _type;
};

void SQLMgr()
{
	if (rand() % 7 == 0)
	{
		throw SqlException("权限不足", 100, "select * from name = '张三'");
	}
	else
	{
		cout << "SQLMgr 调用成功" << endl;
	}
}


void CacheMgr()
{
	if (rand() % 5 == 0)
	{
		throw CacheException("权限不足", 100);
	}
	else if (rand() % 6 == 0)
	{
		throw CacheException("数据不存在", 101);
	}
	else
	{
		cout << "CacheMgr 调用成功" << endl;
	}

	SQLMgr();
}
void HttpServer()
{
	if (rand() % 3 == 0)
	{
		throw HttpException("请求资源不存在", 100, "get");
	}
	else if (rand() % 4 == 0)
	{
		throw HttpException("权限不足", 101, "post");
	}
	else
	{
		cout << "HttpServer调用成功" << endl;
	}

	CacheMgr();
}
//int main()
//{
//	srand(time(0));
//	while (1)
//	{
//		this_thread::sleep_for(chrono::seconds(1));
//		try
//		{
//			HttpServer();
//		}
//		catch (const Exception& e) //这里捕捉基类，基类对象和派生类对象都可以捕捉
//		{
//			cout << e.what() << endl;
//		}
//		catch (...)
//		{
//			cout << "Unknown Exception";
//		}
//	}
//	return 0;
//}

// 下面程序模拟展示了聊天时发送消息，发送失败补货异常，但是可能在
// 电梯地下室等场景手机信号不好，则需要多次尝试，如果多次尝试都发
// 送不出去，则就需要捕获异常再重新抛出，其次如果不是网络差导致的
// 错误，捕获后也要重新抛出。
void _SendMsg(const string& s)
{
	if (rand() % 2 == 0)
	{
		throw HttpException("网络不稳定，发送失败", 102, "put");
	}
	else if (rand() % 7 == 0)
	{
		throw HttpException("你已经不是对象的好友，发送失败", 103, "put");
	}
	else
	{
		cout << "发送成功" << endl;
	}
}

void SendMsg(const string& s)
{
	//发送消息失败，则需要重试三次
	for (size_t i = 0; i < 4; i++)
	{
		try
		{
			_SendMsg(s);
			break;
		}
		catch (const Exception& e)
		{
			if (e.getid() == 102)
				//捕获异常，If中是102号错误，网络不稳定，则重新发送
				//捕获异常，else中不是102号错误，则将异常重新抛出
			{
				if (i == 3)
					throw;
				cout << "开始第" << i + 1 << "重试" << endl;
			}
			else
			{
				throw;
			}
		}
	}
}
//int main()
//{
//	srand(time(0));
//	string str;
//	while (cin >> str)
//	{
//		try
//		{
//			SendMsg(str);
//		}
//		catch (const Exception& e)
//		{
//			cout << e.what() << endl << endl;
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//
//	return 0;
//}
#include <list>

//int main()
//{
//	int i = 0;
//	cout << noexcept(Divide(1, 2)) << endl;
//	cout << noexcept(Divide(1, 0)) << endl;
//	cout << noexcept(++i) << endl;
//}

template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{
	}

	~SmartPtr()
	{
		cout << "delete[] " << _ptr << endl;
		delete[] _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	T& operator[](size_t i)
	{
		return _ptr[i];
	}
private:
	T* _ptr;
};
void Func()
{
	// 这里可以看到如果发生除0错误抛出异常，另外下面的array和array2没有得到释放。
	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再重新抛出去。
	// 但是如果array2new的时候抛异常呢，就还需要套一层捕获释放逻辑，这里更好解决方案
	// 是智能指针，否则代码太戳了
	SmartPtr<int> sp1 = new int[10];
	SmartPtr<int> sp2 = new int[10];   // 抛异常呢
	SmartPtr<int> sp3 = new int[10];   // 抛异常呢
	SmartPtr<int> sp4 = new int[10];   // 抛异常呢
	SmartPtr<pair<int, int>> sp5 = new pair<int, int>[10];   // 抛异常呢

	int len, time;
	cin >> len >> time;
	cout << Divide(len, time) << endl;

	sp1[5] = 50;
	sp5->first = 1;
	sp5->second = 2;
	cout << sp1[5] << endl;
}
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	// 需要sp1和sp2共同管理资源，浅拷贝，析构多次问题得解决
//	SmartPtr<int> sp1 = new int[10];
//	SmartPtr<int> sp2(sp1);
//
//	return 0;
//}

struct Date
{
	int _year;
	int _month;
	int _day;

	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
	}

	~Date()
	{
		cout << "~Date()" << endl;
	}
};
int main()
{
	auto_ptr<Date> ap1(new Date);
	//拷贝时，管理权限转移，被拷贝对象悬空
	auto_ptr<Date> ap2(ap1);

	// 空指针访问，ap1对象已经悬空
	//ap1->_year++;

	unique_ptr<Date> up1(new Date);
	//不支持拷贝

	unique_ptr<Date> up3(move(up1));
	//支持移动，但是移动后up1也悬空，所以使用移动需要谨慎

	//支持拷贝
	shared_ptr<Date> sp1(new Date);
	shared_ptr<Date> sp2(sp1);
	shared_ptr<Date> sp3(sp1);
	sp1->_year++;
	cout << sp1->_year << endl;
	cout << sp2->_year << endl;
	cout << sp3->_year << endl;

	return 0;
}