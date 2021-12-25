#include "Huffman.h"
#include <iostream>
#include "BinaryTree.h"
#include "Item.h"
#include "HashInt.h"
#include "Pair.h"
#include <algorithm>
#include "PriorityQueue.h"
#include <vector>


int getCommon(std::string str, char a) {
    return std::count(str.begin(), str.end(), a);
}

bool compare(BinaryTree<Pair> *tree1, BinaryTree<Pair> *tree2) {
    return tree1->getRoot().count > tree2->getRoot().count;
}

BinaryTree<Pair> *HuffmanTree::buildHuffman(std::string word) {
    MaxHeap<BinaryTree<Pair> *> huffmanPQ(&compare);
    HashInt *hashInt;
    hashInt = new HashInt(word.length());
    for (std::string::iterator itr = word.begin(); itr != word.end(); ++itr) {
        char c = *itr;
        if (hashInt->search(c) == -1)
            // the first occurrence of the current character
        {
            int count = getCommon(word, c);
            hashInt->insert(new Item<int, int>(count, c));
            BinaryTree<Pair> *bt = new BinaryTree<Pair>(Pair(c, count));
            // the key is the char and the value is the amount
            huffmanPQ.push(bt);
        }
    }

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
//    delete huffmanPQ;

    return res;
}