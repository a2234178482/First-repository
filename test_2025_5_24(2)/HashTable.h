#pragma once
#include <vector>
#include <iostream>
using namespace std;
enum State
{
	EXIST,
	EMPTY,
	DELETE
};
template<class K,class V>
struct HashData
{
	pair<K, V> _kv;
	State _state = EMPTY;
};
template<class K>
struct HashFunc
{
	size_t operator()(const K& key) {
		return (size_t)key;
	}
};
template<>
struct HashFunc<string>
{
	size_t operator()(const string& s) {
		size_t hash = 0;
		for (auto ch : s)
		{
			hash += ch;
			hash *= 131;
		}
		return hash;
	}
};
inline unsigned long _stl_next_prime(unsigned long n)
{
	static const int _stl_num_primes = 28;
	static const unsigned long _stl_prime_list[_stl_num_primes] = {
		53, 97, 193, 389, 769,
		1543, 3079, 6151, 12289, 24593,
		49157, 98317, 196613, 393241, 786433,
		1572869, 3145739, 6291469, 12582917, 25165843,
		50331653, 100663319, 201326611, 402653189, 805306457,
		1610612741, 3221225473, 4294967291
	};
	const unsigned long* first = _stl_prime_list;
	const unsigned long* last = _stl_prime_list + _stl_num_primes;
	const unsigned long* pos = lower_bound(first, last, n);
	return pos == last ? *(last - 1) : *pos;
}
namespace open_address
{
	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		HashTable()
			:_tables(_stl_next_prime(0))
			,_n(0)
		{}
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
			{
				return false;
			}
			if (_n * 10 / _tables.size() >= 7)
			{
				HashTable<K, V, Hash> newht;
				for (auto& data : _tables)
				{
					if (data._state == EXIST)
					{
						newht.Insert(data._kv);
					}
				}
				_tables.swap(newht._tables);
			}
			Hash hash;
			size_t hash0 = hash(kv.first) % _tables.size();
			size_t hashi = hash0;
			size_t i = 1;
			int flag = 1;
			while (_tables[hashi]._state == EXIST)
			{
				hashi = (hash0 + i) % _tables.size();
				++i;
			}
			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_n;
			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			Hash hash;
			size_t hash0 = hash(key) % _tables.size();
			size_t hashi = hash0;
			size_t i = 1;
			while (_tables[hashi]._state != EMPTY)
			{
				if (_tables[hashi]._state == EXIST && _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}
				hashi = (hash0 + i) % _tables.size();
				++i;
			}
			return nullptr;
		}
		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				return true;
			}
			else
			{
				return false;
			}
		}
	private:
		vector<HashData<K, V>> _tables;
		size_t n;
	};
}
namespace hash_bucket
{
	template<class K, class  V>
	struct HashNode {
		pair<K, V> _kv;
		HashNode<K, V>* _next;
		HashNode(const pair<K, V>& kv)
			:_kv(kv)
			, _next(nullptr)
		{}
	};
	template<class K,class V,class Hash = HashFunc<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		HashTable()
			:_tables(11)
			,_n(0)
		{ }
		bool Insert(const pair<K, V>& kv)
		{
			if (_n == _tables.size())
			{
				vector<Node*> newTable(_tables.size() * 2);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t hashi = cur->_kv.first % newTable.size();
						cur->_next = newTable[hashi];
						newTable[hashi] = cur;
						cur = next;
					}
					_tables[i] = nullptr;
				}
				_tables.swap(newTable);
			}
			size_t hashi = kv.first % _tables.size();
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;
			return true;
		}
	private:
		vector<Node*> _tables;
		size_t n = 0;
	};
}