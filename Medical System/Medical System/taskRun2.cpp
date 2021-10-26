/*
* Describe: Computerized system for call center management medical.
* Name of develepor 1: Eyal Seckbach. ID: 324863539.
* Name of develepor 2: Liav Ariel.  ID: 212830871.
*/

#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::list;


void main()
{
	char ch;
	Volunteer v;
	Client c;
	list<volunteer*> lst;
	HashTbls ht;

	cout << "Hash Tables\n";
	
	do
	{
		cout << "\nChoose one of the following" << endl;
		cout << "n: New volunteer" << endl;
		cout << "d: Del a volunteer " << endl;
		cout << "c: New client" << endl;
		cout << "l: Add a connection volunteer-client " << endl;
		cout << "*: Print volunteers that helped a client " << endl;
		cout << "i: Print clients that were helped by a voluneer " << endl;
		
		cin >> ch;
		
		switch (ch)
		{
			case 'n':
			{
				cin >> v;
				ht.addVolunteer(v);  
				break;
			}

			case 'd':
			{
				cin >> v.name; 
				ht.delVolunteer(v);  
				break;
			}

			case 'c': 
			{
				cin >> c;
				ht.addClient(c);
				break;
			}

			case 'l': 
			{
				cout << "enter volunteer name and client phone ";  
				cin >> v.name >> c.phone; 
				ht.addVolunteerToClient(v, c); 
				break;
			}

			case '*': 
			{
				cout << "enter client phone "; 
				cin >> c.phone; ht.listOfVolunteers(c);
				break;
			}

			case 'i':
			{
				cout << "enter volunteer name "; 
				cin >> v.name;
				ht.listOfClients(v);
				break;
			}

			case 'e':
			{
				cout << "bye ";
				break;
			}
			
			default: 
			{
				cout << "Error ";  
				break;
			}
		}

	} while (ch != 'e');
}

