#pragma once
#include "Item.h"
#include "Prime.h"
#include <iostream>

using std::cout;
using std::endl;

template <class T, class K>
class HashTbls
{
	public:
		//Consttructors and Destructors
		HashTbls(int size);
		~HashTbls();

		//Additional functions
		virtual int h1(K key) = 0;
		virtual int h2(K key) = 0;
		int hash(K key, int i);
		int search(K key);
		void insert(Item<K, T> item);
		void remove(Item<K, T> item);
		void printTable();

	private:
		Item* _table;
		int _size;
		int _usedSize;
};

template<class T, class K>
inline HashTbls<T, K>::HashTbls(int size)
{
	this->_size = Prime::nextPrime(size);
	this->_table = new Item[this->_size];
	this->_usedSize = 0;

	for (int i = 0; i < this->_size; ++i)
	{
		this->_table[i] = new Item();
	}
}

template<class T, class K>
inline HashTbls<T, K>::~HashTbls()
{
	delete[] this->_table;
	this->_size = 0;
}

template<class T, class K>
inline int HashTbls<T, K>::hash(K key, int i)
{
	return (h1(k) + i*h2(k)) % this->_size;
}

template<class T, class K>
inline int HashTbls<T, K>::search(K key)
{
	bool flag = false;
	bool found = false;
	int index = 0, i = 0;

	while (!flag)
	{
		index = hash(key, i++);

		if (this->_table[index].flag == STATE.Empty || i > this->_size)
		{
			index = -1;
			flag = true;
		}

		else if (this->_table[index].key == key)
		{
			found = true;
			flag = true;
		}
	}
}

template<class T, class K>
inline void HashTbls<T, K>::insert(Item<K, T> item)
{
	bool flag = false;
	int index = 0, i =0;

	if (this->_usedSize == this->_size)
	{
		cout << "Table is full." << endl;
		flag = true;
	}

	while (!flag)
	{
		index = hash(item.key, i++);

		if (this->_table[index].flag == STATE.Empty || this->_table[index].flag == STATE.Deleted)
		{
			this->_table[index].key = item.key;
			this->_table[index].data = item.data;
			this->_table[index].flag = item.flag;
			this->_usedSize++;
			flag = true;
		}
	}
}

template<class T, class K>
inline void HashTbls<T, K>::remove(Item<K, T> item)
{
	int index = search(item.key);
	
	if (index != -1)
	{
		this->_table[index].key = STATE.Deleted;
		this->_usedSize--;
	}

	else
	{
		cout << "Item not found." << endl;
	}
}

template<class T, class K>
inline void HashTbls<T, K>::printTable()
{
	for (int i = 0; i < this->_size; ++i)
	{
		cout << "Key: " << this->_table[i].key << " Data: " << this->_table[i].data << endl;
	}
}
