#include "HashVolunteer.h"
#include "HashTbls.h"
#include <bitset>

using std::bitset;
using std::stoi;

int HashVolunteer::h1(string key, int i) {
    // h(k,i)=(h’(k)+i)mod m
    int cell = ((HashVolunteer::_textToInt(key) % this->_size) + i) % this->_size;
    return cell;
}

int HashVolunteer::h2(string key) { return 1; }

int HashVolunteer::_textToInt(string str) {
    string output;
    for (int i = 0; i < str.length(); ++i) {
        output.append(_toBinary(str[i]));
    }
    string sub = output.substr(0, 31); // in order to not overflow the 'int'

    int num = stoi(sub, nullptr, 2);
    return num;
}

string HashVolunteer::_toBinary(int n) {
    string r;
    while (n != 0) {
        r += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    return r;
}