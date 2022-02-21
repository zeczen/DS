#include "Huffman.h"
#include <iostream>
#include "BinaryTree.h"
#include "Item.h"
#include "HashInt.h"
#include "Pair.h"
#include <algorithm>
#include "PriorityQueue.h"
#include <vector>

using namespace std;

int getCommon(string str, char a) {
    return count(str.begin(), str.end(), a);
}

bool compare(BinaryTree<Pair> *tree1, BinaryTree<Pair> *tree2) {
    return tree1->getRoot().count > tree2->getRoot().count;
}

HuffmanTree::HuffmanTree() {}

HuffmanTree::~HuffmanTree() {
    delete this->tree;
}

string HuffmanTree::treeStructure() {
    return this->tree->getStructure();
}

string HuffmanTree::decode(string encodedText) {
    /* this function receive code and decoded him according to the huffman tree */

    string word = "";
    string decodedText = "";

    vector<Pair> leaves = this->tree->getLeaves();

    for (string::iterator itr = encodedText.begin(); itr != encodedText.end(); ++itr) {
        // we run on every binary digit in the encodedText,
        // until we find that the digits we have is a complete char than we add it to the returned string
        char let = *itr;
        word.push_back(let);
        bool isComplete = false;
        char chr;
        for (vector<Pair>::iterator itr = leaves.begin(); itr != leaves.end(); ++itr) {
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
        decodedText += chr;
        word = "";
    }
    return decodedText;
}

string HuffmanTree::encode(string text) {
    /* this function receive text and encoded him according to the huffman tree */
    vector<Pair> leaves = this->tree->getLeaves();

    string encoded = "";
    for (string::iterator itr = text.begin(); itr != text.end(); ++itr) {
        char let = *itr;
        for (vector<Pair>::iterator itr = leaves.begin(); itr != leaves.end(); ++itr) {
            if (itr->chr == let) {
                encoded += itr->path;
                break;
            }
        }
    }
    return encoded;
}

vector<Pair> HuffmanTree::getLeaves() {
    return this->tree->getLeaves();
}

string HuffmanTree::getLetters() {
    /* this function return all the letters in the huffman tree,
     * sorted from most use to less
     * */
    string letters = "";
    vector<Pair> leaves = this->tree->getLeaves();

    for (vector<Pair>::iterator itr = leaves.begin(); itr != leaves.end(); ++itr) {
        letters += itr->chr;
    }
    return letters;
}

void HuffmanTree::buildHuffman(string treeStructure, string letters) {
    /* this function receive a string that represents the tree structure, a letters,
     * and build huffman tree accordingly
     * */
    vector<Pair> elements;
    for (string::iterator itr = letters.begin(); itr != letters.end(); ++itr)
        elements.push_back(Pair(*itr));

    this->tree = new BinaryTree<Pair>(treeStructure, elements, Pair(0));
    this->tree->setPaths();
}

void HuffmanTree::buildHuffman(string text) {
    /* this function receive a text and build a huffman tree */
    MaxHeap<BinaryTree<Pair> *> huffmanPQ(&compare);
    HashInt *hashInt;
    hashInt = new HashInt(text.length());
    for (string::iterator itr = text.begin(); itr != text.end(); ++itr) {
        char c = *itr;
        if (hashInt->search(c) == -1)
            // the first occurrence of the current character
        {
            int count = getCommon(text, c);
            hashInt->insert(new Item<int, int>(count, c));
            BinaryTree<Pair> *bt = new BinaryTree<Pair>(Pair(c, count));
            // the key is the char and the value is the amount
            huffmanPQ.push(bt);
        }
    }

    // the huffman algorithm
    while (huffmanPQ.size() >= 2) {
        BinaryTree<Pair> *max1 = huffmanPQ.top();
        huffmanPQ.pop();
        BinaryTree<Pair> *max2 = huffmanPQ.top();
        huffmanPQ.pop();

        int sum = max1->getRoot().count + max2->getRoot().count;
        huffmanPQ.push(new BinaryTree<Pair>(Pair(sum), max1, max2));
    }

    BinaryTree<Pair> *res = huffmanPQ.top();
    huffmanPQ.pop();

    res->setPaths();

    delete hashInt;

    this->tree = res;
}