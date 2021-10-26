#pragma once

#include "Item.h"
#include "Prime.h"
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

template<class T, class K>
class HashTbls {
public:
    //Constructors and Destructors
    HashTbls(int size, T t, K k);

    ~HashTbls();

    //Additional functions
    virtual int h1(K key, int i) = 0;

    virtual int h2(K key) = 0;

    int hash(K key, int i);

    int search(K key);

    int size();

    void insert(Item<T, K> *item);

    void _remove(Item<T, K> *item, T t, K k);

    void printTable();

protected:
    std::vector<Item<T, K> *> _table;

    int _size;
    int _usedSize;
};

template<class T, class K>
inline HashTbls<T, K>::HashTbls(int size, T t, K k) {
    this->_size = Prime::nextPrime(size);

    for (std::size_t i = 0; i < this->_size; ++i) {
        this->_table.push_back(new Item<T, K>(t, k));
    }

    this->_usedSize = 0;

}

template<class T, class K>
inline HashTbls<T, K>::~HashTbls() {
    for (int i = 0; i < _usedSize; i++)
        delete this->_table[i];
    this->_size = 0;
}

template<class T, class K>
inline int HashTbls<T, K>::hash(K key, int i) {
    return this->h1(key, i);
}

template<class T, class K>
inline int HashTbls<T, K>::search(K key) {
    int i = 0;
    int index = hash(key, i);

    while (this->_table[index]->flag == Full && this->_table[index]->key != key && i / h2(key) <= this->_size) {
        i += h2(key);
        index = hash(key, i);
    }

    return this->_table[index]->key == key ? index : -1; // nice job here
}

template<class T, class K>
inline void HashTbls<T, K>::insert(Item<T, K> *item) {
    int i = 0;
    int index = this->hash(item->key, i++);

    if (this->_usedSize == this->_size) {
        cout << "Table is full." << endl;
        return;
    }


    while (this->_table[index] == nullptr ||
           this->_table[index]->flag == Full) {
        index = hash(item->key, i++);
    }
    this->_table[index] = item;
    this->_table[index]->flag = Full;

    this->_usedSize++;
}

template<class T, class K>
inline void HashTbls<T, K>::_remove(Item<T, K> *item, T t, K k) {
    int index = search(item->key);

    if (index != -1) {
        this->_usedSize--;
        this->_table[index]->flag = Deleted;
        this->_table[index]->clr(t, k);
    } else {
        cout << "Item not found." << endl;
    }
}

template<class T, class K>
inline void HashTbls<T, K>::printTable() {
    cout << endl;
    for (int i = 0; i < this->_size; ++i) {
        //if (this->_table[i]->flag == Full)
        cout <<
             "Key:" << this->_table[i]->key <<
             "\t\t" << "Data: " << this->_table[i]->data <<
             "\t" << "State: " << this->_table[i]->flag <<
             "\t" << "Index: " << i << endl;
    }
    cout << endl;

}

template<class T, class K>
int HashTbls<T, K>::size() {
    return this->_size;
}
