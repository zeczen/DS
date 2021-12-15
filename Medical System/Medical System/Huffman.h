
#ifndef TEST_HUFFMAN_H
#define TEST_HUFFMAN_H

#include <queue>
#include "BinaryTree.h"
#include "Pair.h"
#include<string.h>

class HuffmanTree {
public:

    HuffmanTree();

    BinaryTree<Pair> buildHuffman(std::string word);

private:
};


#endif //TEST_HUFFMAN_H
