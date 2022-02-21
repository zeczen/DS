/*
* Describe: Computerized system for call center management medical.
* Name of develepor 1: Eyal Seckbach. ID: 324863539.
* Name of develepor 2: Liav Ariel.  ID: 212830871.
*/

#include <iostream>
#include <list>
#include <string>
#include "DT.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	DT t;
	string father, val, sol;
	char ch;

	cout << "\nDECISION TREE\n";
	cout << "Choose one of the following:" << endl;
	cout << "n: New decision tree" << endl;
	cout << "s: Add a new option for a question" << endl;
	cout << "d: Delete a subtree" << endl;
	cout << "p: Print all tree" << endl;
	cout << "w: Print how to get a node" << endl;
	cout << "r: Run a process of questions" << endl;
	cout << "t: Print to a string" << endl;
	cout << "e: exit:" << endl;

	do
	{
		cin >> ch;
		switch (ch)
		{
			case 'n':
			{
				cout << "enter the main question (with no space) ";
				cin >> val;
				t = DT(val);
				break;
			}

			case 's':
			{
				cout << "enter the question (with no space) ";
				cin >> father;

				cout << "enter the new answer (with no space) ";
				cin >> val;

				cout << "enter the new solution(possible a new question, with no space) ";
				cin >> sol;

				if (t.addNode(father, val, sol))
				{
					cout << "success\n";
				}

				else
				{
					cout << "ERROR\n";
				}

				break;
			}

			case 'd':
			{
				cout << "enter value of subtree to delete (with no space) ";
				cin >> val;
				t.removeSubTree(val);
				break;
			}

			case 'p':
			{
				t.print();
				break;
			}

			case 'w':
			{
				cout << "enter a value (with no space) ";
				cin >> val;
				t.printPath(val);
				cout << endl;
				break;
			}

			case 'r':
			{
				t.run();
				cout << endl;
				break;
			}

			case 'e':
			{
				cout << "bye ";
				break;
			}

			case 't':
			{
				cout << t.printToString();
				cout << endl;
				break;
			}

			default:
			{
				cout << "ERROR\n";
				break;
			}
		}

	} while (ch != 'e');

	return 0;
}
