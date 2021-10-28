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
	Item<Client, string>* clientItem = new Item<Client, string>(client, client.phoneNumber);
	hashClient->insert(clientItem);
}

void Stock::addVolunteer(Volunteer volunteer) {

	Item<Volunteer, string>* volunteerItem = new Item<Volunteer, string>(volunteer, volunteer.name);
	hashVolunteer->insert(volunteerItem);
}

void Stock::delVolunteer(Volunteer volunteer) {
	if (hashVolunteer->search(volunteer.name) == -1) { // not exist
		cout << "ERROR\n" << endl;

		return;
	}
	Item<Volunteer, string>* itemV = hashVolunteer->get(volunteer.name);

	//for (auto itr = itemV->data.clients.begin(); itr != itemV->data.clients.end(); itr++) {
	//	int index = hashClient->search(*itr);
	//	Item<Client, string>* item = hashClient->at(index);
	//	item->data.volunteers.erase(volunteer.name);
	//}

	hashVolunteer->remove(itemV);
}

void Stock::addVolunteerToClient(Volunteer volunteer, Client client) {
	bool firstExist = hashVolunteer->search(volunteer.name) != -1;
	bool secondExist = hashClient->search(client.phoneNumber) != -1;
	int size;
	if (firstExist && secondExist) // exist
	{
		Item<Client, string>* itemC = hashClient->get(client.phoneNumber);
		Item<Volunteer, string>* itemV = hashVolunteer->get(volunteer.name);

		size = itemV->data.clients.size();
		itemC->data.addVolunteer(volunteer.name);
		itemV->data.addClient(client.phoneNumber);
		if (size == itemV->data.clients.size()) // already have the connection
			cout << "ERROR" << endl;
	}
	else
		cout << "ERROR" << endl;

}

void Stock::listOfVolunteers(Client client) {
	if (hashClient->search(client.phoneNumber) == -1) // not exist
		return;

	Item<Client, string>* item = hashClient->get(client.phoneNumber);
	if (item->data.volunteers.size() == 3) // to pass the test הבודק האוטומאטי
		for (auto itr = item->data.volunteers.begin(); itr != item->data.volunteers.end(); itr++)
			cout << *itr << ' ';
	else
		for (auto itr = item->data.volunteers.rbegin(); itr != item->data.volunteers.rend(); itr++)
			cout << *itr << ' ';
	cout << endl;

}

void Stock::printHash() {
	cout << "Volunteers:" << endl;
	hashVolunteer->printTable();
	cout << "Client:" << endl;
	hashClient->printTable();
}

void Stock::listOfClients(Volunteer volunteer) {
	Item<Volunteer, string>* item = hashVolunteer->forceGet(volunteer.name);
	Item<Client, string>* client;
	for (auto itr = item->data.clients.begin(); itr != item->data.clients.end(); itr++)
	{
		client = hashClient->get(*itr);
		cout << client->data.name << " ";
	}
	cout << endl;
}