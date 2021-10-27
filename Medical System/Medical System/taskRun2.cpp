/*
* Describe: Computerized system for call center management medical.
* Name of developer 1: Eyal Seckbach. ID: 324863539.
* Name of developer 2: Liav Ariel. ID: 212830871.
*/

#include <iostream>
#include <string>
#include <list>
#include "HashInt.h"
#include "HashTbls.h"
#include "HashVolunteer.h"
#include "Client.h"
#include "Volunteer.h"
#include "Stock.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::list;


int _main() {
    HashVolunteer *hashVolunteer = new HashVolunteer(10);
    Item<Volunteer, string> *f = new Item<Volunteer, string>(Volunteer("eyal", "hacnasart", "522222222", "Tekoa"),
                                                             "Eyal");
    Item<Volunteer, string> *s = new Item<Volunteer, string>(Volunteer("david", "gat", "500000000", "Jerusalem"),
                                                             "Liav");
    Item<Volunteer, string> *t = new Item<Volunteer, string>(Volunteer("ariel", "patron", "588888888", "Natania"),
                                                             "Ariel");
    hashVolunteer->insert(f);
    hashVolunteer->insert(s);
    hashVolunteer->insert(t);
    hashVolunteer->printTable();
    hashVolunteer->remove(f);
    hashVolunteer->printTable();

    return 0;
}


int main() {
    char ch;
    Volunteer v;
    Client c;
    list<Volunteer *> lst;
    Stock stock;

    cout << "Hash Tables\n";
    do {
        cout << "\nChoose one of the following" << endl;
        cout << "n: New volunteer" << endl;
        cout << "d: Del a volunteer " << endl;
        cout << "c: New client" << endl;
        cout << "l: Add a connection volunteer-client " << endl;
        cout << "*: Print volunteers that helped a client " << endl;
        cout << "i: Print clients that were helped by a voluneer " << endl;
        cin >> ch;
        switch (ch) {
            case 'n':
                cin >> v;
                stock.addVolunteer(v);
                break;
            case 'd':
                cin >> v.name;
                stock.delVolunteer(v);
                break;
            case 'c':
                cin >> c;
                stock.addClient(c);
                break;
            case 'l':
                cout << "enter volunteer name and client phone ";
                cin >> v.name >> c.phoneNumber;
                stock.addVolunteerToClient(v, c);
                break;
            case '*':
                cout << "enter client phone ";
                cin >> c.phoneNumber;
                stock.listOfVolunteers(c);
                break;
            case 'i':
                cout << "enter volunteer name ";
                cin >> v.name;
                stock.listOfClients(v);
                break;
            case 'e':
                cout << "bye ";
                break;
            default:
                cout << "Error ";
                break;
        }
    } while (ch != 'e');
    return 0;
}
