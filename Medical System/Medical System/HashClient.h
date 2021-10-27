#ifndef DS_HASHCLIENT_H
#define DS_HASHCLIENT_H


#include "HashTbls.h"
#include "Client.h"

using std::string;

class HashClient : public HashTbls<Client, string> {
public:

    HashClient(int size) : HashTbls<Client, string>::HashTbls(size, Client(), "") {}

    void remove(Item<Client, string> *item) {
        this->_remove(item, Client(), "");
    }

    int h1(string key, int i);

    int h2(string key);

    int _textToInt(string words);

    string _toBinary(int n);

};

#endif //DS_HASHCLIENT_H
