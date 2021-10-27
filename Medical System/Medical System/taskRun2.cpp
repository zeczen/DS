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
                cout << "Enter volunteer name phone address" << endl;
                cin >> v;
                stock.addVolunteer(v);
                break;
            case 'd':
                cin >> v.name;
                stock.delVolunteer(v);
                break;
            case 'c':
                cout << "please enter name and phone and address of client " << endl;
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
                cout << "The volunteers that helped to client " << c.phoneNumber << ": ";
                stock.listOfVolunteers(c);
                cout << endl;

                break;
            case 'i':
                cout << "enter volunteer name ";
                cin >> v.name;
                stock.listOfClients(v);
                break;
            case 'p':
                stock.printHash();
                break;
            case 'e':
                cout << "Bye";
                break;
            default:
                cout << "Error ";
                break;
        }
    } while (ch != 'e');
    return 0;
}
