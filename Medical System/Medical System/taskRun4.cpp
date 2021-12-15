#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "Huffman.h"
#include "Pair.h"


int main() {
    char choice;


    HuffmanTree *t;
    std::cout << "enter E to encode a text\n";
    std::cout << "enter D to decode a text\n";
    std::cout << "enter X to exit\n";

    std::string word;


    do {
        std::cin >> choice;
        switch (choice) {
            case 'E': {

                std::cout << "enter the original text" << std::endl;
                std::cin >> word;
                BinaryTree<Pair> encoded = t->buildHuffman(word);
                // Build Huffman tree given the data inside "word".
                // Then find the code of each letter.
                std::vector<Pair> leaves = encoded.getLeaves();
                std::cout << leaves.size();
                // Then print the output - number of leaves,

                // order of letters,
                // tree structure and the encoded text -
                // according to the explanation in the exercise.

                break;
            }
            case 'D': {
                int i = 0;
                // input the number of leaves, the  order of letters, tree structure and the encoded text.
                // build the Huffman Tree according to the tree structure.
                // put the letters in the leaves according to the given order.
                // Given the Huffman Tree and the encoded text, find the original text, and print it.
            }
        }

    } while (choice != 'X');
    return 0;
}