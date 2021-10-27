
#ifndef DS_VOLUNTER_H
#define DS_VOLUNTER_H

#include<string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;
using std::endl;

class Volunteer {
public:
    string name;
    string address;
    string phoneNumber;
    string city;
public:

    Volunteer(string n, string a, string p, string c) :
            name(n), address(a), phoneNumber(p), city(c) {}

    Volunteer() :
            name(""), address(""), phoneNumber(""), city("") {}

    ~Volunteer() {}

    bool operator==(Volunteer &v) {
        return this->name.compare(v.name);
    }

    void operator=(Volunteer &v) {
        this->name = v.name;
        this->address = v.address;
        this->phoneNumber = v.phoneNumber;
        this->city = v.city;
    }

    friend istream &operator>>(istream &is, Volunteer &volunteer) {
        string n;
        string a;
        string p;
        string c;
        is >> n >> a >> p >> c;
        volunteer.name = n;
        volunteer.address = a;
        volunteer.phoneNumber = p;
        volunteer.city = c;
        return is;
    }

    friend ostream &operator<<(ostream &os, const Volunteer &v) {
        os << "Volunteer["
              "Name: " << v.name << ", " <<
           "address: " << v.address << ", " <<
           "phoneNumber: " << v.phoneNumber << ", " <<
           "city: " << v.city << ']';
        return os;
    }
};


#endif //DS_VOLUNTER_H
