#ifndef DS_HASHVOLNTEER_H
#define DS_HASHVOLNTEER_H

#include "HashTbls.h"
#include "Volunteer.h"

using std::string;

class HashVolunteer : public HashTbls<Volunteer, string> {
public:

    HashVolunteer(int size) : HashTbls<Volunteer, string>::HashTbls(size, Volunteer(), "") {}

    void remove(Item<Volunteer, string>* item) {
        this->_remove(item, Volunteer(), "");
    }

    int h1(string key, int i);

    int h2(string key);

    int _textToInt(string words);

    string _toBinary(int n);

};


#endif //DS_HASHVOLNTEER_H
