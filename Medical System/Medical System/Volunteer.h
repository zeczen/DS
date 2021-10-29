
#ifndef DS_VOLUNTER_H
#define DS_VOLUNTER_H

#include<string>
#include <iostream>
#include <set>


using std::string;
using std::ostream;
using std::istream;
using std::endl;
using std::cout;
using std::set;


class Volunteer {
public:
    string name;
    string phoneNumber;
    string city;
    set<string> clients;

public:

    Volunteer(string n, string p, string c) :
            name(n), phoneNumber(p), city(c) {}

    Volunteer() :
            name(""), phoneNumber(""), city("") {}

    ~Volunteer() {}

    void addClient(string client) { this->clients.insert(client); }

    bool operator==(Volunteer &v) {
        return this->name.compare(v.name);
    }

    void operator=(Volunteer &v) {
        this->name = v.name;
        this->phoneNumber = v.phoneNumber;
        this->city = v.city;
    }

    friend istream &operator>>(istream &is, Volunteer &volunteer) {

        string n;
        string p;
        string c;
        is >> n >> p >> c;
        volunteer.name = n;
        volunteer.phoneNumber = p;
        volunteer.city = c;
        return is;
    }

    friend ostream &operator<<(ostream &os, const Volunteer &v) {
        os
                << v.name << ":volunteer" << " "
                << "name=" << v.name << " "
                << "phone=" << v.phoneNumber << " "
                << "address=" << v.city;
        return os;
    }
};


#endif //DS_VOLUNTER_H
