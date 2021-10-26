#pragma once

enum STATE {
    Empty, Full, Deleted
};

template<class T, class K>
class Item {
public:
    T data;
    K key;
    STATE flag;

    Item(T t, K k) {
        clr(t, k);
        this->flag = Empty;
    }

    void clr(T t, K k) {
        this->data = t;
        this->key = k;
    }
};