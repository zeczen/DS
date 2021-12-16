#include "Huffman.h"
#include<iostream>
#include "BinaryTree.h"
#include "Item.h"
#include "HashInt.h"
#include "Pair.h"
#include <algorithm>
#include "updatable_priority_queue.h"


int getCommon(std::string str, char a) {
    return std::count(str.begin(), str.end(), a);
}

BinaryTree<Pair> &HuffmanTree::buildHuffman(std::string word) {
    /* TODO:
     * How to define huffmanPQ: if type of <BinaryTree<Pair*> > we get garbage value,
     * if type of <BinaryTree<Pair*> *> the '<' and '>' operators not called on BinaryTree type but on the address of them in the memory
     * !!!
     */
    int i = 0;
    PQ::updatable_priority_queue<int, BinaryTree<Pair>> huffmanPQ; // priority queue declaration
    HashInt *hashInt;
    hashInt = new HashInt(word.length());
    for (char &c: word) {
        if (hashInt->search(c) == -1)
            // the first occurrence of the current character
        {
            int count = getCommon(word, c);
            hashInt->insert(new Item<int, int>(count, c));
            // the key is the char and the value is the amount
            huffmanPQ.push(i++, BinaryTree<Pair>(Pair(c, count)));
            std::cout << huffmanPQ.size() << std::endl;

        }
    }

    while (huffmanPQ.size() >= 2) {
        auto max1 = huffmanPQ.pop_value();
        auto max2 = huffmanPQ.pop_value();


        int sum = max1.priority.getRoot().count + max2.priority.getRoot().count;
        huffmanPQ.push(i++, BinaryTree<Pair>(Pair(sum)), sum);

    }

    BinaryTree<Pair> res = huffmanPQ.pop_value().priority;

    res.setPaths();

    delete hashInt;
//    delete huffmanPQ;

    return res;
}