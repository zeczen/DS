#ifndef DS_STOCK_H
#define DS_STOCK_H

#include "HashVolunteer.h"
#include "HashClient.h"
#include "Client.h"
#include "Volunteer.h"

class Stock {
public:
    HashVolunteer *hashVolunteer;
    HashClient *hashClient;

    Stock();

    ~Stock();

    void addClient(Client);

    void addVolunteer(Volunteer);

    void delVolunteer(Volunteer);

    void addVolunteerToClient(Volunteer, Client);

    void printHash();

    void listOfVolunteers(Client);

    void listOfClients(Volunteer);
};


#endif //DS_STOCK_H
