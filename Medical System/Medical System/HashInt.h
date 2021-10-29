
#ifndef DS_HASHINT_H
#define DS_HASHINT_H

#include "HashTbls.h"

class HashInt : public HashTbls<int, int> {
public:

    HashInt(int size) : HashTbls<int, int>::HashTbls(size, 0, 0) {}

    void remove(Item<int, int>* item){
        this->_remove(item, 0, 0);
    }

    int h1(int key, int i) {
        // h(k,i)=(h’(k)+i)mod m
        int cell = ((key % this->_size) + i) % this->_size;
        return cell;
    }


    int h2(int key) { return 1; }
};


#endif //DS_HASHINT_H
