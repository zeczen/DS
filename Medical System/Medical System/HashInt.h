
#ifndef DS_HASHINT_H
#define DS_HASHINT_H

#include "HashTbls.h"

class HashInt : public HashTbls<int, int> {
public:

    HashInt(int size) : HashTbls<int, int>::HashTbls(size, 0, 0) {}

    void remove(Item<int, int>* item){
        this->_remove(item, 0, 0);
    }
    int h1(int key, int i);

    int h2(int key);
};


#endif //DS_HASHINT_H
