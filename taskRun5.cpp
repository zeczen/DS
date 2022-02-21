/*
* Describe: Computerized system for call center management medical.
* Name of developer 1: Eyal Seckbach. ID: 324863539.
* Name of developer 2: Liav Ariel. ID: 212830871.
*/

#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph g;
    try {
        string v1, v2, name;
        int choice;
        cout << endl;
        cout << "Choose one of the following:" << endl;
        cout << "1-to add a task" << endl;
        cout << "2 - to add a priority rule" << endl;
        cout << "3 - to print all the graph" << endl;
        cout << "4 - print a recommended task order" << endl;
        cout << "5 - exit" << endl;
        do {
            cin >> choice;
            switch (choice) {
                case 1: {
                    cout << "Enter the task you want to add" << endl;
                    cin >> v1;
                    if (!g.addVertex(v1)) cout << "ERROR" << endl;
                    break;
                }
                case 2: {
                    cout << "Enter earlier task and the later task" << endl;
                    cin >> v1 >> v2;
                    if (!g.addEdge(v1, v2)) cout << "ERROR" << endl;
                    break;
                }
                case 3: {
                    cout << "The graph:" << endl;
                    g.printAll();
                    cout << endl;
                    break;
                }
                case 4: {
                    cout << "The recommended order:" << endl;
                    cout << g.topologicalSort();
                    cout << endl;
                    break;
                }
                case 5: {
                    cout << "byebye";
                    break;
                }
                default: {
                    cout << "ERROR" << endl;

                }
            }
        } while (choice != 5);
    }
    catch (string s) {
        cout << s << endl;
    }
    return 0;
}