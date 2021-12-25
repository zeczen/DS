/*
* Describe: Computerized system for call center management medical.
* Name of developer 1: Eyal Seckbach. ID: 324863539.
* Name of developer 2: Liav Ariel. ID: 212830871.
*/

#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "Huffman.h"
#include "Pair.h"
#include <string>

using namespace std;

bool checkInput(int ones, string tree, string letters) {
    int j = 0;
    for (int i = 0; i <= tree[i]; i++) {
        if (tree[i] == '1') {
            j++;
        }
    }
    return (j == ones) && (j == letters.length());
}

int main() {
    char choice;


    HuffmanTree *t = new HuffmanTree();
    cout << "enter E to encode a text\n";
    cout << "enter D to decode a text\n";
    cout << "enter X to exit\n";


    do {
        cin >> choice;
        switch (choice) {
            case 'E': {
                string word;

                cout << "enter the original text" << endl;
                cin >> word;

                cout << "The encoded string is" << endl;

                t->buildHuffman(word);  // Build Huffman tree given the data
                string letters = t->getLetters();
                cout << letters.size() << endl;

                // print the order of letters
                cout << letters << endl;

                // print the tree structure
                cout << endl << t->treeStructure() << endl;

                // print the encoded message
                cout << endl << t->encode(word) << endl;

                break;
            }
            case 'D': {
                int numLeaves;
                string letters;
                string treeStructure;
                string encodedText;

                cout << "enter n" << endl;
                cin >> numLeaves;

                cout << "enter the letters" << endl;
                cin >> letters;

                cout << "enter the encoded structure" << endl;
                cin >> treeStructure;

                cout << "enter the encoded text" << endl;
                cin >> encodedText;

                if (!checkInput(numLeaves, treeStructure, letters)) {
                    cout << "ERROR" << endl;
                    cout << "bye" << endl;
                    return 0;
                }

                cout << "The decoded string is" << endl;

                t->buildHuffman(treeStructure, letters);

                cout << t->decode(encodedText) << endl;

                break;
            }
        }

    } while (choice != 'X');

    delete t;

    cout << "bye" << endl;

    return 0;
}