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

using std::cout;
using std::cin;
using std::endl;
using std::list;


int main() {
    cout << "start\n";
    HashInt *hashInt = new HashInt(10);
    Item<int, int> *f = new Item<int, int>(1, 11); // 11 % 11
    Item<int, int> *s = new Item<int, int>(2, 11+2); // 11 + 2 % 11 = 2
    Item<int, int> *t = new Item<int, int>(3, 2);
    hashInt->insert(f);
    hashInt->insert(s);
    hashInt->insert(t);
    hashInt->printTable();
    hashInt->remove(f);
    hashInt->printTable();

    return 0;
}


//int main() {
//    char ch;
//    Volunteer v;
//    Client c;
//    list<volunteer *> lst;
//    HashTbls ht;
//
//    cout << "Hash Tables\n";
//
//    do {
//        cout << "\nChoose one of the following" << endl;
//        cout << "n: New volunteer" << endl;
//        cout << "d: Del a volunteer " << endl;
//        cout << "c: New client" << endl;
//        cout << "l: Add a connection volunteer-client " << endl;
//        cout << "*: Print volunteers that helped a client " << endl;
//        cout << "i: Print clients that were helped by a voluneer " << endl;
//
//        cin >> ch;
//
//        switch (ch) {
//            case 'n': {
//                cin >> v;
//                ht.addVolunteer(v);
//                break;
//            }
//
//            case 'd': {
//                cin >> v.name;
//                ht.delVolunteer(v);
//                break;
//            }
//
//            case 'c': {
//                cin >> c;
//                ht.addClient(c);
//                break;
//            }
//
//            case 'l': {
//                cout << "enter volunteer name and client phone ";
//                cin >> v.name >> c.phone;
//                ht.addVolunteerToClient(v, c);
//                break;
//            }
//
//            case '*': {
//                cout << "enter client phone ";
//                cin >> c.phone;
//                ht.listOfVolunteers(c);
//                break;
//            }
//
//            case 'i': {
//                cout << "enter volunteer name ";
//                cin >> v.name;
//                ht.listOfClients(v);
//                break;
//            }
//
//            case 'e': {
//                cout << "bye ";
//                break;
//            }
//
//            default: {
//                cout << "Error ";
//                break;
//            }
//        }
//
//    } while (ch != 'e');
//}

