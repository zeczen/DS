#include "Huffman.h"
#include<iostream>
#include <queue>
#include "BinaryTree.h"
#include "Item.h"
#include "HashInt.h"
#include "Pair.h"
#include <algorithm>


int getCommon(std::string str, char a) {
    return std::count(str.begin(), str.end(), a);
}

BinaryTree<Pair> HuffmanTree::buildHuffman(std::string word) {
    /* TODO:
     * How to define p: if type of <BinaryTree<Pair> > we get garbage value,
     * if type of <BinaryTree<Pair> *> the '<' and '>' operators not called on BinaryTree type but on the address of them in the memory
     * !!!
     */
    std::priority_queue<BinaryTree<Pair> > *p;  // priority queue declaration
    HashInt *hashInt;
    hashInt = new HashInt(word.length());
    p = new std::priority_queue<BinaryTree<Pair> >();

    for (char &c: word) {
        if (hashInt->search(c) == -1)
            // the first occurrence of the current character
        {
            int count = getCommon(word, c);
            hashInt->insert(new Item<int, int>(count, c));
            // the key is the char and the value is the amount
            BinaryTree<Pair> node = BinaryTree<Pair>(Pair(c, count));
            p->push(node);
        }
    }

    while (p->size() >= 2) {
        BinaryTree<Pair> max1 = p->top();
        p->pop();
        BinaryTree<Pair> max2 = p->top();
        p->pop();
        p->push(
                BinaryTree<Pair>(
                        Pair(max1.getRoot().count +
                             max2.getRoot().count)
                )
        );


    } // p->size is 1

    BinaryTree<Pair> res = p->top();
    res.setPaths();

    delete hashInt;
    delete p;

    return res;
}