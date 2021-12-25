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

bool checkInput(int ones, std::string tree, std::string letters) {
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


    HuffmanTree *t;
    std::cout << "enter E to encode a text\n";
    std::cout << "enter D to decode a text\n";
    std::cout << "enter X to exit\n";


    do {
        std::cin >> choice;
        switch (choice) {
            case 'E': {
                std::string word;

                std::cout << "enter the original text" << std::endl;
                std::cin >> word;

                std::cout << "The encoded string is" << std::endl;

                BinaryTree<Pair> *encoded = t->buildHuffman(
                        word);  // Build Huffman tree given the data inside "word".
                std::vector<Pair> leaves = encoded->getLeaves();
                std::cout << leaves.size() << std::endl;

                // order of letters,
                for (std::vector<Pair>::iterator itr = leaves.begin(); itr != leaves.end(); ++itr) {
                    std::cout << itr->chr;
                }
                std::cout << std::endl << encoded->getStructure() << std::endl;

                for (std::string::iterator itr = word.begin(); itr != word.end(); ++itr) {
                    char let = *itr;
                    for (std::vector<Pair>::iterator itr = leaves.begin(); itr != leaves.end(); ++itr) {
                        if (itr->chr == let) {
                            std::cout << itr->path;
                            break;
                        }
                    }
                }
                std::cout << std::endl;

                delete encoded;
                break;
            }
            case 'D': {
                int numLeaves;
                std::string letters;
                std::string treeStructure;
                std::string encodedText;

                std::cout << "enter n" << std::endl;
                std::cin >> numLeaves;

                std::cout << "enter the letters" << std::endl;
                std::cin >> letters;

                std::cout << "enter the encoded structure" << std::endl;
                std::cin >> treeStructure;

                std::cout << "enter the encoded text" << std::endl;
                std::cin >> encodedText;

                if (!checkInput(numLeaves, treeStructure, letters)) {
                    std::cout << "ERROR" << std::endl;
                    std::cout << "bye" << std::endl;

                    return 0;
                }

                std::cout << "The decoded string is" << std::endl;

                std::vector<Pair> elements;
                for (std::string::iterator itr = letters.begin(); itr != letters.end(); ++itr) {
                    char let = *itr;
                    elements.push_back(Pair(let));
                }
                BinaryTree<Pair> *bt = new BinaryTree<Pair>(treeStructure, elements, Pair(0));
                bt->setPaths();

                std::vector<Pair> leaves = bt->getLeaves();

                std::string word = "";


                for (std::string::iterator itr = encodedText.begin(); itr != encodedText.end(); ++itr) {
                    char let = *itr;
                    word.push_back(let);
                    bool isComplete = false;
                    char chr;
                    for (std::vector<Pair>::iterator itr = leaves.begin(); itr != leaves.end(); ++itr) {
                        Pair &leave = *itr;
                        if (leave.path == word) {
                            isComplete = true;
                            chr = leave.chr;
                            break;
                        }
                    }
                    if (!isComplete) {
                        continue;
                    }

                    // we found the word
                    std::cout << chr;
                    word = "";
                }
                std::cout << std::endl;

                delete bt;
            }
        }

    } while (choice != 'X');

    std::cout << "bye" << std::endl;

    return 0;
}