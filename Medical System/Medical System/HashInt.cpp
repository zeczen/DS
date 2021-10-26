#include "HashInt.h"
#include "HashTbls.h"

int HashInt::h1(int key, int i) {
    // h(k,i)=(h’(k)+i)mod m
    int cell = ((key % this->_size) + i) % this->_size;
    return cell;
}

int HashInt::h2(int key) { return 1; }
