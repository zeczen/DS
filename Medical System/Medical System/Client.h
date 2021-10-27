#ifndef DS_CLIENT_H
#define DS_CLIENT_H

#include<string>
#include <iostream>
#include <set>
#include "Volunteer.h"
#include "HashVolunteer.h"


using std::string;
using std::istream;
using std::ostream;
using std::set;
using std::endl;

class Client {
public:
    string name;
    string address;
    string phoneNumber;
    string city;
    set<Volunteer> volunteers;
public:
    Client(string n, string a, string p, string c) :
            name(n), address(a), phoneNumber(p), city(c) {}

    Client() :
            name(""), address(""), phoneNumber(""), city("") {}

    ~Client() {}

    void addVolunteer(Volunteer volunteer) { volunteers.insert(volunteer); }

    friend istream &operator>>(istream &is, Client &client) {
        string n;
        string a;
        string p;
        string c;
        is >> n >> a >> p >> c;
        client.name = n;
        client.address = a;
        client.phoneNumber = p;
        client.city = c;
        return is;
    }

    friend ostream &operator<<(ostream &os, const Client &c) {
        os << "Client["
              "Name: " << c.name << ", " <<
           "address: " << c.address << ", " <<
           "phoneNumber: " << c.phoneNumber << ", " <<
           "city: " << c.city << ", " <<
           "volunteers:{";
        for (auto itr = c.volunteers.begin(); itr != c.volunteers.end(); itr++)
            os << *itr << ", ";

        os << '}]';

        return os;
    }
};


#endif //DS_CLIENT_H
