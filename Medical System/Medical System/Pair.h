
#ifndef TEST_PAIR_H
#define TEST_PAIR_H

class Pair {
public:
    Pair(char c, int i) {
        this->chr = c;
        this->count = i;
    }

    Pair(int i) {
        this->count = i;
    }

    std::string path;
    char chr;
    int count;
};


#endif //TEST_PAIR_H
