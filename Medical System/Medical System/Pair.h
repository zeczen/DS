
#ifndef TEST_PAIR_H
#define TEST_PAIR_H

class Pair {
public:
    Pair(char c, int i) {
        this->path = "";
        this->chr = c;
        this->count = i;
    }

    Pair(int i) {
        this->path = "";
        this->chr = '-';
        this->count = i;
    }

    bool operator<(const Pair p) {
        return this->count > p.count;
    }

    bool operator>(const Pair p) {
        return this->count < p.count;
    }



    std::string path;
    char chr;
    int count;
};


#endif //TEST_PAIR_H
