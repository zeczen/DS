#ifndef DS_CLIENT_H
#define DS_CLIENT_H

#include<string>
#include <iostream>
#include <set>
#include "HashVolunteer.h"


using std::string;
using std::istream;
using std::ostream;
using std::set;
using std::endl;

class Client {
public:
    string name;
    string phoneNumber;
    string city;
    set<string> volunteers;
public:
    Client(string n, string a, string p, string c) :
            name(n), phoneNumber(p), city(c) {}

    Client() : name(""), phoneNumber(""), city("") {}

    ~Client() {}

    void addVolunteer(string volunteer) {
        this->volunteers.insert(volunteer);
    }

    friend istream &operator>>(istream &is, Client &client) {
        string n;
        string p;
        string c;
        is >> n >> p >> c;
        client.name = n;
        client.phoneNumber = p;
        client.city = c;
        return is;
    }

    friend ostream &operator<<(ostream &os, const Client &c) {
        os
                << c.phoneNumber << ":client" << " "
                << "name: " << c.name << " "
                << "phone: " << c.phoneNumber << " "
                << "address: " << c.city;
        if (c.volunteers.size() != 0) {
            os << " helped by: ";
            for (auto itr = c.volunteers.begin(); itr != c.volunteers.end(); itr++)
                os << *itr << ' ';
        }
        return os;
    }
};


#endif //DS_CLIENT_H
