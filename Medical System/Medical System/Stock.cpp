#include "Stock.h"
#include "Item.h"
#include "Client.h"
#include "Volunteer.h"

Stock::Stock() {
    hashVolunteer = new HashVolunteer(100);
    hashClient = new HashClient(100);
}

Stock::~Stock() {
    delete hashVolunteer;
    delete hashClient;
}

void Stock::addClient(Client client) {
    Item<Client, string> *clientItem = new Item<Client, string>(client, client.phoneNumber);
    hashClient->insert(clientItem);
}

void Stock::addVolunteer(Volunteer volunteer) {
    Item<Volunteer, string> *volunteerItem = new Item<Volunteer, string>(volunteer, volunteer.phoneNumber);
    hashVolunteer->insert(volunteerItem);
}

void Stock::delVolunteer(Volunteer) {

}

void Stock::addVolunteerToClient(Volunteer volunteer, Client client) {
    if(hashVolunteer->search(volunteer.phoneNumber) != -1) // exist
        client.
}

void Stock::listOfVolunteers(Client) {}

void Stock::listOfClients(Volunteer) {}

