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

    int h1(string key, int i) {
        // h(k,i)=(h’(k)+i)mod m
        int cell = ((HashClient::_textToInt(key) % this->_size) + i) % this->_size;
        return cell;
    }

    int h2(string key) { return 1; }

    int _textToInt(string str) {
        string output;
        for (int i = 0; i < str.length(); ++i) {
            output.append(_toBinary(str[i]));
        }
        string sub = output.substr(0, 31); // in order to not overflow the 'int'

        int num = stoi(sub, nullptr, 2);
        return num;
    }

    string _toBinary(int n) {
        string r;
        while (n != 0) {
            r += (n % 2 == 0 ? "0" : "1");
            n /= 2;
        }
        return r;
    }

};

#endif //DS_HASHCLIENT_H
