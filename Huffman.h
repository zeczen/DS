
#ifndef TEST_HUFFMAN_H
#define TEST_HUFFMAN_H

#include <queue>
#include "BinaryTree.h"
#include "Pair.h"
#include<string.h>

using namespace std;

class HuffmanTree {
public:

    HuffmanTree();

    ~HuffmanTree();

    string getLetters();

    string treeStructure();

    string encode(string text);

    string decode(string encodedText);

    void buildHuffman(string);

    void buildHuffman(string treeStructure, string letters);

private:
    vector<Pair> getLeaves();

    BinaryTree<Pair> *tree;
};


#endif //TEST_HUFFMAN_H
