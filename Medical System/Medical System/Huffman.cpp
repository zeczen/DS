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
    /* TODO:
     * How to define huffmanPQ: if type of <BinaryTree<Pair*> > we get garbage value,
     * if type of <BinaryTree<Pair*> *> the '<' and '>' operators not called on BinaryTree type but on the address of them in the memory
     * !!!
     */
    MaxHeap<BinaryTree<Pair> *> huffmanPQ(&compare);
    HashInt *hashInt;
    hashInt = new HashInt(word.length());
    for (char c: word) {
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
        auto max1 = huffmanPQ.top();
        huffmanPQ.pop();
        auto max2 = huffmanPQ.top();
        huffmanPQ.pop();


        int sum = max1->getRoot().count + max2->getRoot().count;
        huffmanPQ.push(new BinaryTree<Pair>(Pair(sum), max2, max1));

    }

    BinaryTree<Pair> *res = huffmanPQ.top();
    huffmanPQ.pop();

    res->setPaths();

    delete hashInt;
//    delete huffmanPQ;

    return res;
}